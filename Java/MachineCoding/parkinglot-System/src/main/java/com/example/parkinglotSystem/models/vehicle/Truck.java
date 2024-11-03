package com.example.parkinglotSystem.models.vehicle;

import com.example.parkinglotSystem.models.enums.VehicleType;

public class Truck extends Vehicle {
    public Truck(String registrationNumber, String color) {
        super(registrationNumber, color);
    }
    @Override
    public VehicleType getType() {
        return VehicleType.TRUCK;
    }
}
