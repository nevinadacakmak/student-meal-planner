from django.urls import path, include
from rest_framework.routers import DefaultRouter
from .views import RecipeViewSet, MealPlanViewSet

router = DefaultRouter()
router.register(r'recipes', RecipeViewSet)
router.register(r'mealplans', MealPlanViewSet)

urlpatterns = [
    path('', include(router.urls)),
]
