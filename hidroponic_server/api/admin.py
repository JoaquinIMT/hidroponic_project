from django.contrib import admin

from .models import *

admin.site.register(PH)
admin.site.register(WaterTank)
admin.site.register(RoomTemperature)
admin.site.register(WaterTray)
admin.site.register(SoilHumidity)
admin.site.register(TankElectroconductivity)

admin.site.register(PHRange)
admin.site.register(WaterTankRange)
admin.site.register(RoomTemperatureRange)
admin.site.register(WaterTrayRange)
admin.site.register(SoilHumidityRange)
admin.site.register(TankElectroconductivityRange)

