package com.example.parkinglotSystem.strategy;

import com.example.parkinglotSystem.models.entities.Ticket;

public class BasicPricingStrategy implements PricingStrategy{
    private static final double HOURLY_RATE = 10.0;

    @Override
    public double calculatePrice(Ticket ticket){
        long hoursParked = Math.max(ticket.getParkingDuration().toHours(), 1); // At least 1 hour
        return hoursParked * HOURLY_RATE;
    }
}
