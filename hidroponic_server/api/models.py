from django.db import models
from .utils import BasicRange, BasicRecord
from django.db import models

class PH(BasicRecord):
    name = 'PH'

class WaterTank(BasicRecord):
    name = 'Watter tank'

class RoomTemperature(BasicRecord):
    name='Room Temperature'
    cooling_sys = models.BooleanField(default=False)

class WaterTray(BasicRecord):
    name = 'Watter tray'
    out_valve = models.BooleanField(default=False)
    in_valve = models.BooleanField(default=False)

class SoilHumidity(BasicRecord):
    name = 'Soil Humidity'

class TankElectroconductivity(BasicRecord):
    name = 'Tank Electroconductivity'

class PHRange(BasicRange):
    name = 'PH range'

class WaterTankRange(BasicRange):
    name = 'Watter tank range'

class RoomTemperatureRange(BasicRange):
    name = 'Room Temperature'

class WaterTrayRange(BasicRange):
    name = 'Watter tray range'

class SoilHumidityRange(BasicRange):
    name = 'Soil Humidity range'

class TankElectroconductivityRange(BasicRange):
    name = 'Tank Electroconductivity range'
