package com.example.parkinglotSystem.strategy;

import com.example.parkinglotSystem.models.entities.Floor;
import com.example.parkinglotSystem.models.entities.ParkingLot;
import com.example.parkinglotSystem.models.entities.Ticket;
import com.example.parkinglotSystem.models.vehicle.Vehicle;

public class FirstAvailableStrategy implements ParkingStrategy{
    @Override
    public Ticket park(ParkingLot parkingLot, Vehicle vehicle){
        for(Floor floor: parkingLot.getFloors()){
            Ticket ticket = floor.parkVehicle(parkingLot.getId(), vehicle);
            if(ticket != null) return ticket;
        }
        return null;
    }
}
