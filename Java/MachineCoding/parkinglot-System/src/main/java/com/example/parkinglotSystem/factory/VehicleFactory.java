package com.example.parkinglotSystem.factory;

import com.example.parkinglotSystem.models.enums.VehicleType;
import com.example.parkinglotSystem.models.vehicle.Bike;
import com.example.parkinglotSystem.models.vehicle.Car;
import com.example.parkinglotSystem.models.vehicle.Truck;
import com.example.parkinglotSystem.models.vehicle.Vehicle;

public class VehicleFactory {
    public static Vehicle createVehicle(VehicleType type, String registrationNumber, String color) throws Exception{
        Vehicle vehicle;
        switch (type){
            case CAR:
                vehicle = new Car(registrationNumber, color);
                break;
            case BIKE:
                vehicle = new Bike(registrationNumber, color);
                break;
            case TRUCK:
                vehicle = new Truck(registrationNumber, color);
                break;
            default:
                System.out.println("Unknown vehicle type");
                throw new IllegalArgumentException("Unknown vehicle type");
        }
        return vehicle;
    }
}
