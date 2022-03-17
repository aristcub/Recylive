from django.shortcuts import render
from django.http import HttpResponse

def home(request):
    searchTerm = request.GET.get('searchResident')
    return render (request, 'home.html',{'searchTerm':searchTerm})

def about(request):
    return HttpResponse('Welcome to About page</h1>')

# Create your views here.
