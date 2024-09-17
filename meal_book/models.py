from django.db import models
from django.contrib.auth.models import User

class Recipe(models.Model): # Recipe model
    name = models.CharField(max_length=100)
    ingredients = models.TextField()
    instructions = models.TextField()
    calories = models.IntegerField()
    image = models.ImageField(upload_to='recipes/', blank=True, null=True)

class MealPlan(models.Model): # Meal Plan model
    user = models.ForeignKey(User, on_delete=models.CASCADE)
    date = models.DateField()
    recipes = models.ManyToManyField(Recipe)

class UserProfile(models.Model): # User Profile model
    user = models.OneToOneField(User, on_delete=models.CASCADE)
    dietary_restrictions = models.TextField(blank=True, null=True)
    budget = models.DecimalField(max_digits=10, decimal_places=2, default=0.00)
