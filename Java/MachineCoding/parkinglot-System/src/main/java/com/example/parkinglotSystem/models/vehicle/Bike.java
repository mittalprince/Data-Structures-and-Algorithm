package com.example.parkinglotSystem.models.vehicle;

import com.example.parkinglotSystem.models.enums.VehicleType;

public class Bike extends Vehicle {
    public Bike(String registrationNumber, String color) {
        super(registrationNumber, color);
    }
    @Override
    public VehicleType getType() {
        return VehicleType.BIKE;
    }
}
