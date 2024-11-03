package com.example.parkinglotSystem.models.entities;

import com.example.parkinglotSystem.models.enums.VehicleType;
import com.example.parkinglotSystem.models.vehicle.Vehicle;

import java.util.Vector;

public class ParkingSlot {
    private final int slotNumber;
    private boolean isOccupied;
    private final VehicleType type;
    private Vehicle vehicle;

    public ParkingSlot(int slotNumber, VehicleType type) {
        this.slotNumber = slotNumber;
        this.type = type;
        this.isOccupied = false;
    }

    public int getSlotNumber() { return slotNumber; }
    public boolean isOccupied() {
        return isOccupied;
    }

    public VehicleType getType() {
        return type;
    }
    public void park(Vehicle vehicle) {
        this.vehicle = vehicle;
        this.isOccupied = true;
    }

    public void unPark() {
        this.vehicle = null;
        this.isOccupied = false;
    }
    public boolean isAvailableForPark(VehicleType vehicleType){
        return !isOccupied && isAvailableFor(vehicleType);
    }
    public boolean isOccupiedSlot(VehicleType vehicleType){
        return isOccupied && isAvailableFor(vehicleType);
    }
    private boolean isAvailableFor(VehicleType vehicleType){
        return type.equals(vehicleType);
    }
}

