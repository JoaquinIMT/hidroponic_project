from django.db import models

class BasicRecord(models.Model):
    value = models.IntegerField(default=0)  
    date = models.DateTimeField('date_time of sample')

class BasicRange(models.Model):
    upper = models.IntegerField(default=0)
    lower = models.IntegerField(default=0)