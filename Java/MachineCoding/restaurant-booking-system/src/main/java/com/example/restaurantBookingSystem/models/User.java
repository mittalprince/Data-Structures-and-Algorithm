package com.example.restaurantBookingSystem.models;

public class User {
    private String id;
    private String name;

    public User(String id, String name) {
        this.id = id;
        this.name = name;
    }

    public String getId() {
        return id;
    }

    @Override
    public String toString() {
        return String.format("User{id='%s', name='%s'}", id, name);
    }
}
