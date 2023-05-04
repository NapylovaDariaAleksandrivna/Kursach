from django.db import models

# Create your models here.
class Continent(models.Model):
    continent_name=models.CharField(max_length=30)
    continent_img=models.TextField(blank=True)

    def __str__(self):
        return self.continent_name
    
class Country(models.Model):
    continent=models.ForeignKey(
        Continent, on_delete=models.CASCADE, related_name="country")
    country_name=models.CharField(max_length=30)
    flag=models.TextField(blank=True)#blank=True не обязательно писать в поле
    
    def __str__(self):
        return self.country_name
    
class City(models.Model):
    country=models.ForeignKey(Country, on_delete=models.CASCADE, related_name="city")
    city_name=models.CharField(max_length=30)

    def __str__(self):
        return self.city_name
    
class DateWeather(models.Model):
    city=models.ForeignKey(City, on_delete=models.CASCADE, related_name="dateweather")
    date=models.DateField()
    weather_status=models.CharField(max_length=30)
    status_icon=models.CharField(max_length=30, blank=True)
    wind_speed=models.IntegerField()
    humidity=models.IntegerField()
    temperature=models.IntegerField()

    def __str__(self):
        return '{} {}'.format(str(self.city), str(self.date))
