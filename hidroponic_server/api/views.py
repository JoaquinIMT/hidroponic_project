from django.shortcuts import render
from django.http import HttpResponse, JsonResponse
from .models import *
# Create your views here.

def index(request):
    return HttpResponse("Hello world")

def get_ranges(request):
    response = {}
    ph = PHRange
    wt = WaterTankRange
    rt = RoomTemperatureRange
    wtr = WaterTrayRange
    sh = SoilHumidityRange
    te = TankElectroconductivityRange
    ranges = [ph, wt, rt, wtr, sh, te]
    for range in ranges:
        response[range.name] = list(ph.objects.all().values())[0]
    return JsonResponse(response, safe=False)

