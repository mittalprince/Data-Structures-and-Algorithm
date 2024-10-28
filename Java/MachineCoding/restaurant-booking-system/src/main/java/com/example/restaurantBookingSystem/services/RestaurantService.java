package com.example.restaurantBookingSystem.services;

import com.example.restaurantBookingSystem.models.Restaurant;

import java.util.ArrayList;
import java.util.List;

public class RestaurantService {
    private static RestaurantService instance;
    private List<Restaurant> restaurants;

    private RestaurantService() {
        restaurants = new ArrayList<>();
    }

    public static RestaurantService getInstance() {
        if (instance == null) {
            instance = new RestaurantService();
        }
        return instance;
    }

    public void registerRestaurant(String name, String city, String area, String cuisine, String[] timeSlots) {
        String id = String.valueOf(restaurants.size() + 1); // Simple ID generation
        Restaurant restaurant = new Restaurant(id, name, city, area, cuisine);
        for (String slot : timeSlots) {
            restaurant.addTimeSlot(slot);
        }
        restaurants.add(restaurant);
    }

    public List<Restaurant> searchRestaurants(String city) {
        List<Restaurant> result = new ArrayList<>();
        for (Restaurant restaurant : restaurants) {
            if (restaurant.getCity().equalsIgnoreCase(city)) {
                result.add(restaurant);
            }
        }
        return result;
    }

    public Restaurant getRestaurantById(String id) {
        for (Restaurant restaurant : restaurants) {
            if (restaurant.getId().equals(id)) {
                return restaurant;
            }
        }
        return null;
    }
}
