from django.contrib import admin
from myApp.models import Continent,Country,City,DateWeather
 
admin.site.register (Continent)
admin.site.register(Country)
admin.site.register (City)

@admin.register(DateWeather)
class DateWeatherAdmin(admin.ModelAdmin):
    list_display=['city','date']