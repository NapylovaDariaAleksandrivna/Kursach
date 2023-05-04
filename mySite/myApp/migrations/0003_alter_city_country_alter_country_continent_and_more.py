# Generated by Django 4.1.7 on 2023-04-17 16:45

from django.db import migrations, models
import django.db.models.deletion


class Migration(migrations.Migration):

    dependencies = [
        ('myApp', '0002_alter_city_city_name'),
    ]

    operations = [
        migrations.AlterField(
            model_name='city',
            name='country',
            field=models.ForeignKey(on_delete=django.db.models.deletion.CASCADE, to='myApp.country'),
        ),
        migrations.AlterField(
            model_name='country',
            name='continent',
            field=models.ForeignKey(on_delete=django.db.models.deletion.CASCADE, to='myApp.continent'),
        ),
        migrations.AlterField(
            model_name='dateweather',
            name='city',
            field=models.ForeignKey(on_delete=django.db.models.deletion.CASCADE, to='myApp.city'),
        ),
    ]
