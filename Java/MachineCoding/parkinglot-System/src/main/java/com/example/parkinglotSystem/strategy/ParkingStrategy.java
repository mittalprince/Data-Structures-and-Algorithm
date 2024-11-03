package com.example.parkinglotSystem.strategy;

import com.example.parkinglotSystem.models.entities.ParkingLot;
import com.example.parkinglotSystem.models.entities.Ticket;
import com.example.parkinglotSystem.models.vehicle.Vehicle;

public interface ParkingStrategy {
    Ticket park(ParkingLot parkingLot, Vehicle vehicle);
}
