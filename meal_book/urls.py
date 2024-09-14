from django.urls import path, include
from rest_framework.routers import DefaultRouter
from . import views

router = DefaultRouter()
router.register(r'recipes', views.RecipeViewSet)
router.register(r'meal-plans', views.MealPlanViewSet)

urlpatterns = [
    path('', views.home, name='home'),  # This is for the homepage
    path('api/', include(router.urls)),  # API endpoints
]
