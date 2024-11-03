package com.example.parkinglotSystem.models.vehicle;

import com.example.parkinglotSystem.models.enums.VehicleType;

public abstract class Vehicle {
    private final String registrationNumber;
    private final String color;

    public Vehicle(String registrationNumber, String color) {
        this.registrationNumber = registrationNumber;
        this.color = color;
    }

    public String getRegistrationNumber() { return registrationNumber; }
    public String getColor() { return color; }
    public abstract VehicleType getType();
}
