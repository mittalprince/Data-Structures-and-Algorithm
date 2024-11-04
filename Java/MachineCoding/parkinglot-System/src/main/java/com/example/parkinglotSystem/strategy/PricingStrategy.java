package com.example.parkinglotSystem.strategy;

import com.example.parkinglotSystem.models.entities.Ticket;

public interface PricingStrategy {
    double calculatePrice(Ticket ticket);
}
