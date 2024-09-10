from rest_framework import viewsets
from .models import Recipe, MealPlan
from .serializers import RecipeSerializer, MealPlanSerializer

class RecipeViewSet(viewsets.ModelViewSet):
    queryset = Recipe.objects.all()
    serializer_class = RecipeSerializer

class MealPlanViewSet(viewsets.ModelViewSet):
    queryset = MealPlan.objects.all()
    serializer_class = MealPlanSerializer
