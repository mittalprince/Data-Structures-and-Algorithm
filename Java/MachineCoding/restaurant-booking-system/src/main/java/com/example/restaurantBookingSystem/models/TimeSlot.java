package com.example.restaurantBookingSystem.models;

public class TimeSlot {
    private String time;
    private boolean isBooked;

    public TimeSlot(String time) {
        this.time = time;
        this.isBooked = false;
    }

    public String getTime() {
        return time;
    }

    public boolean isBooked() {
        return isBooked;
    }

    public void bookSlot() {
        this.isBooked = true;
    }
}
