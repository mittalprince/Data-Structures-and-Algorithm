package com.example.restaurantBookingSystem.view;

import com.example.restaurantBookingSystem.models.Restaurant;

import java.util.List;

public class RestaurantView {
    public void displayRestaurants(List<Restaurant> restaurants) {
        System.out.println("Found Restaurants:");
        for (Restaurant restaurant : restaurants) {
            System.out.println("- " + restaurant.getName() + " (ID: " + restaurant.getId() + ")");
            System.out.print("Available Slots: ");
            restaurant.getAvailableSlots().forEach(slot -> {
                if (!slot.isBooked()) {
                    System.out.print(slot.getTime() + " ");
                }
            });
            System.out.println();
        }
    }

    public void displayBookingStatus(boolean success) {
        if (success) {
            System.out.println("Booking successful!");
        } else {
            System.out.println("Booking failed. Please try again.");
        }
    }
}
