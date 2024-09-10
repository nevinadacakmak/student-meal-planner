from django.db import models
from django.contrib.auth.models import User

class Recipe(models.Model):
    name = models.CharField(max_length=200)
    ingredients = models.TextField()
    instructions = models.TextField()
    nutritional_info = models.JSONField()

    def __str__(self):
        return self.name

class MealPlan(models.Model):
    user = models.ForeignKey(User, on_delete=models.CASCADE)
    recipes = models.ManyToManyField(Recipe)
    date = models.DateField()

    def __str__(self):
        return f"{self.user.username}'s Meal Plan for {self.date}"
