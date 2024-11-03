package com.example.parkinglotSystem.services;

import com.example.parkinglotSystem.factory.VehicleFactory;
import com.example.parkinglotSystem.models.entities.ParkingLot;
import com.example.parkinglotSystem.models.entities.Ticket;
import com.example.parkinglotSystem.models.enums.VehicleType;
import com.example.parkinglotSystem.models.vehicle.Vehicle;
import com.example.parkinglotSystem.strategy.ParkingStrategy;

public class ParkingService {
    private final ParkingLot parkingLot;

    public ParkingService(ParkingLot parkingLot){
        this.parkingLot = parkingLot;
    }

    public Ticket parkVehicle(VehicleType vehicleType, String regNo, String color) throws Exception {
        Vehicle vehicle = VehicleFactory.createVehicle(vehicleType, regNo, color);
        return parkingLot.parkVehicle(vehicle);
    }

    public void unParkVehicle(Ticket ticket) throws Exception {
        parkingLot.unParkVehicle(ticket);
    }
}
