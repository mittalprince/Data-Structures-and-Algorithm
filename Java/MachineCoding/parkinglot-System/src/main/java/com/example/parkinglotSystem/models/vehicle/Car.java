package com.example.parkinglotSystem.models.vehicle;

import com.example.parkinglotSystem.models.enums.VehicleType;

public class Car extends Vehicle {
    public Car(String registrationNumber, String color) {
        super(registrationNumber, color);
    }
    @Override
    public VehicleType getType() {
        return VehicleType.CAR;
    }
}
