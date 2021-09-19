//Libraries and definitions
#include <DHT.h>
#define DHTPIN 2
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);  
//Nutrient Film Control Method
//Core set up elements:
//Air stone; water pump, channel (1 to 30 slope;FR), Timer, Net Pots,Reservior, air tubes, water tubes


//pin ports variables
//inputs 
const int sensor_humidity = A0;
const int sensor_tray_water_leve = A1;
const int sensor_tray_water_leve = A1;
//outputs
const int actuator_bomb = 3;
const int actuator_valve= 4;
const int actuator_cooling = 5;

//State Variables 
float upper_limit_ph = 5.5;//limit for securing nutrients absortion; water quality
float lower_limit_ph = 6.5;
float upper_limit_water_level;
float lower_lmit_water_level;
float upper_limit_tray_water_level;
float lower_lmit_tray_water_level;
float upper_limit_Temp;
float lower_lmit_Temp;
int upper_limit_humidity;
int lower_lmit_humidity;
float upper_limit_ElectroC = 1500;
float lower_lmit_ElectroC = 1200;// minimum minerals (Ca,NaCl,H) and nutrients concentrarion in water;
float feeding_tray_time;
float upper_limit_Waterflow;
float lower_lmit_Waterflow;
int chanel_num;
int chanel_slope;
//Dinamic Variables
float water_level;
float soil_humidity;
float ElectroC;
float tray_water_level;
float log_ElectroC;
float temp;
float nutrients_change;




//sensors read_data_pretotype_Functions
void read_ph(void);
void read_tray_water_Level(void);
void read_water_Level(void);
void read_channel_WaterFlow(void);
void read_Temp(void);
void read_humidity(void);
void read_electroconductivity_msfa(void);
void read_nutrientSol(void);
float Nutrient_REQ(float,float);

//Actuators_Control_pretotype_functions
void bomb_Turn_on(void);
void bomb_Turn_off(void);
void open_Nutrient_supply_valve(void);
void close_supply_valve(void);
void reservior_Watersupply_open(void);
void reservior_Watersupply_close(void);
void cooling_on(void);
void cooling_off(void);
void all_actuators_shutdown(void);





void read_ph(){
    int SensorValue = analogRead(sensorPin);
    return(SensorValue);
}
void read_water_tray_Level(){
    float sensorValue = analogRead(analogInPin);
    sensorValue = 100/1024;
    return(sensorValue);
}
void read_Temp(){
    float h = dht.readHumidity();
    float t = dht.readTemperature();
    float f = dht.readTemperature(true);
    if (isnan(h) || isnan(t) || isnan(f)) {
        Serial.println("Error obteniendo los datos del sensor DHT11");
        return upper_limit_Temp;
    }
    float sensorvalue = dht.computeHeatIndex(t, h, false);
    return sensorvalue

}
void read_humidity(){
    
}
void read_electroconductivity_ppm(){
    
}
float Nutrient_Sol(float electroC,float ph_level ){

}
void bomb_Turn_on(){
    Digitalwrite(actuator_bomb,HIGH);
}
void bomb_Turn_off(){
    Digitalwrite(actuator_bomb,LOW);
}  


void all_actuators_shutdown(){
    bomb_Turn_off;
    close_supply_valve();


}



void setup() {
  Serial.begin(9600);
  //inputs
  PinMode(sensor_humidity,INPUT);
  //output
  PinMode(actuator_bomb,OUTPUT);
  PinMode(actuator_valve,OUTPUT);
  PinMode(actuator_cooling,OUTPUT);
  all_actuators_shutdown();

  

}

//Process Flow


void loop() {
  temp = read_Temp();
  if(temp>upper_limit_Temp){
      cooling_on();
  }
  else{
      if(temp<lower_lmit_Temp){
          cooling_off();
      }
  }

  soil_humidity = read_humidity();
  water_level = read_water_Level();
  if(water_level<lower_lmit_water_level){
    reservior_Watersupply_open();
  }
  else{
      if(water_level>upper_limit_water_level){
          reservior_Watersupply_close();
      }
      
  }
  if(soil_humidity<lower_lmit_humidity){
    nutrients_change = log_ElectroC;
    ElectroC =  read_electroconductivity_ppm();//reading Nutrient concentration in reservior
    nutrients_change = ElectroC-nutrients_change;
    if(ElectroC<lower_lmit_ElectroC){
        open_Nutrient_supply_valve();
        while(ElectroC<lower_lmit_ElectroC){
            ElectroC =  read_electroconductivity_ppm();
            temp = read_Temp();
            if(temp<lower_limit_Temp){
                cooling_off();
            }
            if(ElectroC>upper_limit_ElectroC){
                close_supply_valve();
                break;
            }
        }
    }
    log_ElectroC = ElectroC;
    bomb_Turn_on();
    tray_water_level = read_tray_water_Level();
    if(tray_water_level>upper_limit_tray_water_level){
        bomb_Turn_off();
        }
    }
    soil_humidity = read_humidity();
    else{
        if(soil_humidity>upper_limit_humidity){
            bomb_Turn_off();
        }
    }

    
  }


  
  
  
  
  
  





}
