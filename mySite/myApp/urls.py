from django.urls import path
from . import views
from django.contrib import admin
from django.contrib import admin
from django.urls import path
from myApp import views

urlpatterns = [
    
    path('', views.home),
    path('admin/', admin.site.urls),

    path('continentsAll/', views.ContinentListAll.as_view()),

    path('continents/<str:continent_name>/', views.ContinentList.as_view({'get':'list'})),
    path('continents/<str:continent_name>/<str:country_name>/', views.ContinentList.as_view({'get':'retrieve'})),
    path('continents/<str:continent_name>/<str:country_name>/<str:city_name>/', views.ContinentList.as_view({'get':'retrieve'})),

    path('countries/', views.CountryList.as_view()),
    path('cities/', views.CityList.as_view()),
    path('weather/', views.DateWeatherList.as_view())
    
]

