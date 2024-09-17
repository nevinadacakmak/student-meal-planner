from django.urls import path, include
from rest_framework.routers import DefaultRouter
from .views import MealPlanViewSet, RecipeViewSet, UserProfileViewSet

router = DefaultRouter()
router.register(r'meal-plans', MealPlanViewSet)
router.register(r'recipes', RecipeViewSet)
router.register(r'user-profiles', UserProfileViewSet)

urlpatterns = [
    path('api/', include(router.urls)),
]