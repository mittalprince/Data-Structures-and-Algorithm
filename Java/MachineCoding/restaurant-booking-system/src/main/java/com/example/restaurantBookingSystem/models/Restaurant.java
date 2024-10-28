package com.example.restaurantBookingSystem.models;

import com.example.restaurantBookingSystem.models.TimeSlot;

import java.util.ArrayList;
import java.util.List;

public class Restaurant {
    private String id;
    private String name;
    private String city;
    private String area;
    private String cuisine;
    private List<TimeSlot> availableSlots;

    public Restaurant(String id, String name, String city, String area, String cuisine) {
        this.id = id;
        this.name = name;
        this.city = city;
        this.area = area;
        this.cuisine = cuisine;
        this.availableSlots = new ArrayList<>();
    }

    public void addTimeSlot(String time) {
        availableSlots.add(new TimeSlot(time));
    }

    public String getId() {
        return id;
    }

    public String getName() {
        return name;
    }

    public String getCity(){ return city; }

    public List<TimeSlot> getAvailableSlots() {
        return availableSlots;
    }
}
