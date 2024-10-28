package com.example.restaurantBookingSystem.services;

import com.example.restaurantBookingSystem.models.Restaurant;
import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class BookingServiceTest {
    @Test
    void testBookTable_Success() {
        RestaurantService restaurantService = RestaurantService.getInstance();
        restaurantService.registerRestaurant("Pasta Place", "New York", "Downtown", "Italian", new String[]{"12:00-13:00"});

        BookingService bookingService = new BookingService(restaurantService);
        boolean result = bookingService.bookTable("1", 2, "12:00-13:00");

        assertTrue(result);
        Restaurant restaurant = restaurantService.getRestaurantById("1");
        assertTrue(restaurant.getAvailableSlots().get(0).isBooked());
    }

    @Test
    void testBookTable_Failure() {
        RestaurantService restaurantService = RestaurantService.getInstance();
        restaurantService.registerRestaurant("Pasta Place", "New York", "Downtown", "Italian", new String[]{"12:00-13:00"});

        BookingService bookingService = new BookingService(restaurantService);
        bookingService.bookTable("1", 2, "12:00-13:00"); // Book the slot first
        boolean result = bookingService.bookTable("1", 2, "12:00-13:00"); // Try to book again

        assertFalse(result);
    }
}
