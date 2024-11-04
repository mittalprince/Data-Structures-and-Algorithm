package com.example.parkinglotSystem.strategy;

import com.example.parkinglotSystem.models.entities.Ticket;
import com.example.parkinglotSystem.models.enums.VehicleType;

public class VehicleTypePricingStrategy implements PricingStrategy{
    private static final double CAR_RATE = 10.0;
    private static final double BIKE_RATE = 5.0;
    private static final double TRUCK_RATE = 15.0;

    @Override
    public double calculatePrice(Ticket ticket){
        long hoursParked = Math.max(ticket.getParkingDuration().toHours(), 1); // At least 1 hour
        VehicleType vehicleType = ticket.getVehicle().getType();

        switch (vehicleType) {
            case CAR:
                return hoursParked * CAR_RATE;
            case BIKE:
                return hoursParked * BIKE_RATE;
            case TRUCK:
                return hoursParked * TRUCK_RATE;
            default:
                throw new IllegalArgumentException("Unknown vehicle type");
        }
    }
}
