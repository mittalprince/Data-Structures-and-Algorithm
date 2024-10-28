package com.example.restaurantBookingSystem.services;

import com.example.restaurantBookingSystem.models.Restaurant;
import com.example.restaurantBookingSystem.models.TimeSlot;

public class BookingService {
    private final RestaurantService restaurantService;

    public BookingService(RestaurantService restaurantService) {
        this.restaurantService = restaurantService;
    }

    public boolean bookTable(String restaurantId, int numberOfPeople, String timeSlot) {
        Restaurant restaurant = restaurantService.getRestaurantById(restaurantId);
        if (restaurant != null) {
            for (TimeSlot slot : restaurant.getAvailableSlots()) {
                if (slot.getTime().equals(timeSlot) && !slot.isBooked()) {
                    slot.bookSlot();
                    return true;
                }
            }
        }
        return false;
    }
}
