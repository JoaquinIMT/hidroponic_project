from django.urls import path

from . import views

urlpatterns = [
    path('', views.index, name='index'),
    path('ph_ranges', views.get_ranges, name='ranges')
]
