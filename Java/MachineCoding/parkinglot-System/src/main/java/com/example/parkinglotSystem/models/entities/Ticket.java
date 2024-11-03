package com.example.parkinglotSystem.models.entities;

import com.example.parkinglotSystem.models.vehicle.Vehicle;

public class Ticket {
    private final String id;
    private final Vehicle vehicle;
    private final int floorNumber;
    private final int slotNumber;

    public Ticket(String parkingLotId, Vehicle vehicle, int floorNumber, int slotNumber) {
        this.id = parkingLotId + "_" + floorNumber + "_" + slotNumber;
        this.vehicle = vehicle;
        this.floorNumber = floorNumber;
        this.slotNumber = slotNumber;
    }

    public String getId() { return id; }
    public Vehicle getVehicle() { return vehicle; }
    public int getFloorNumber() { return floorNumber; }
    public int getSlotNumber() { return slotNumber; }
}
