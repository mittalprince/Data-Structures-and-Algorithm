package com.example.parkinglotSystem.models.entities;

import com.example.parkinglotSystem.models.vehicle.Vehicle;
import com.example.parkinglotSystem.strategy.PricingStrategy;

import java.time.Duration;
import java.time.LocalDateTime;

public class Ticket {
    private final String id;
    private final Vehicle vehicle;
    private final int floorNumber;
    private final int slotNumber;
    private LocalDateTime entryTime;
    private LocalDateTime exitTime;
    private PricingStrategy pricingStrategy;
    private double price = 0;

    public Ticket(String parkingLotId, Vehicle vehicle, int floorNumber, int slotNumber) {
        this.id = parkingLotId + "_" + floorNumber + "_" + slotNumber;
        this.vehicle = vehicle;
        this.floorNumber = floorNumber;
        this.slotNumber = slotNumber;
        // set entry time & pricingStrategy
    }

    public String getId() { return id; }
    public Vehicle getVehicle() { return vehicle; }
    public int getFloorNumber() { return floorNumber; }
    public int getSlotNumber() { return slotNumber; }

    // Set exit time and calculate price
    public void setExitTime(LocalDateTime exitTime) {
        this.exitTime = exitTime;
        this.price = pricingStrategy.calculatePrice(this); // Calculate price using assigned strategy
    }

    public Duration getParkingDuration() {
        return Duration.between(entryTime, exitTime);
    }

    public double getPrice() {
        return price;
    }
}
