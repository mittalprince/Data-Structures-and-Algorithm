package com.example.restaurantBookingSystem.models;

public class Booking {
    private String restaurantId;
    private int numOfPeople;
    private String timeSlot;

    public Booking(String restaurantId, int numberOfPeople, String timeSlot) {
        this.restaurantId = restaurantId;
        this.numOfPeople = numberOfPeople;
        this.timeSlot = timeSlot;
    }

    @Override
    public String toString() {
        return String.format("Booking{restaurantId='%s', numberOfPeople=%d, timeSlot='%s'}", restaurantId, numOfPeople, timeSlot);
    }
}
