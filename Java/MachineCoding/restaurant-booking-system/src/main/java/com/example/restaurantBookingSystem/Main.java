package com.example.restaurantBookingSystem;

import com.example.restaurantBookingSystem.controllers.RestaurantController;

public class Main {
    public static void main(String[] args) {
        RestaurantController controller = new RestaurantController();
        controller.run();
    }
}
