from django.db import models
from distutils.command import upload
from quopri import decodestring

class Residente(models.Model):
    nombre = models.CharField(max_length=100)
    apartamento = models.CharField(max_length=50)
    cedula = models.IntegerField()
    telefono = models.IntegerField()
    puntos = models.IntegerField(blank=True)

# (3) modelo de premios
    



