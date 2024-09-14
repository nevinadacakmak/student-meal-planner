from rest_framework import viewsets
from .models import Recipe, MealPlan
from .serializers import RecipeSerializer, MealPlanSerializer
from django.http import HttpResponse

def home(request):
    return HttpResponse("Welcome to the Meal Planner App!")


class RecipeViewSet(viewsets.ModelViewSet):
    queryset = Recipe.objects.all()
    serializer_class = RecipeSerializer

class MealPlanViewSet(viewsets.ModelViewSet):
    queryset = MealPlan.objects.all()
    serializer_class = MealPlanSerializer
