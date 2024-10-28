package com.example.restaurantBookingSystem.controllers;

import com.example.restaurantBookingSystem.models.Restaurant;
import com.example.restaurantBookingSystem.services.BookingService;
import com.example.restaurantBookingSystem.services.RestaurantService;
import com.example.restaurantBookingSystem.view.RestaurantView;

import java.util.List;
import java.util.Scanner;

public class RestaurantController {
    private RestaurantService restaurantService;
    private BookingService bookingService;
    private RestaurantView restaurantView;

    public RestaurantController() {
        this.restaurantService = RestaurantService.getInstance();
        this.bookingService = new BookingService(restaurantService);
        this.restaurantView = new RestaurantView();
    }

    public void run() {
        registerRestaurant();
        searchRestaurant();
    }

    private void registerRestaurant() {
        restaurantService.registerRestaurant("The Good Place", "New York", "Downtown", "Italian", new String[]{"12:00-13:00", "19:00-20:00"});
        restaurantService.registerRestaurant("Test Diner", "Los Angeles", "Hollywood", "American", new String[]{"11:00-12:00", "13:00-14:00"});
    }

    private void searchRestaurant() {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter city to search for restaurants: ");
        String city = scanner.nextLine();
        List<Restaurant> restaurants = restaurantService.searchRestaurants(city);
        restaurantView.displayRestaurants(restaurants);
        if (!restaurants.isEmpty()) {
            System.out.print("Enter restaurant ID to book a table: ");
            String restaurantId = scanner.nextLine();
            System.out.print("Enter number of people: ");
            int numberOfPeople = scanner.nextInt();
            System.out.print("Enter time slot: ");
            String timeSlot = scanner.next();

            boolean booked = bookingService.bookTable(restaurantId, numberOfPeople, timeSlot);
            restaurantView.displayBookingStatus(booked);
        }
        scanner.close();
    }
}
