package com.example.parkinglotSystem.services;

import com.example.parkinglotSystem.models.entities.ParkingLot;
import com.example.parkinglotSystem.models.enums.DisplayType;
import com.example.parkinglotSystem.models.enums.VehicleType;

public class DisplayService {
    private final ParkingLot parkingLot;

    public DisplayService(ParkingLot parkingLot) {
        this.parkingLot = parkingLot;
    }

    public void displayMessage(String message){
        System.out.println(message);
    }
    public void display(DisplayType displayType, VehicleType vehicleType){
        switch (displayType){
            case FREE_COUNT:
                displayFreeCount(vehicleType);
                break;
            case FREE_SLOTS:
                displayFreeSlots(vehicleType);
                break;
            case OCCUPIED_SLOTS:
                displayOccupiedSlots(vehicleType);
                break;
            default:
                displayMessage("Invalid display type: " + displayType);
                break;
        }
    }

    private void displayFreeCount(VehicleType vehicleType) {
        for (int floorNumber = 1; floorNumber <= parkingLot.getNumberOfFloors(); floorNumber++) {
            int freeSlotsCount = parkingLot.getFreeSlotsCount(floorNumber-1, vehicleType);
            displayMessage("No. of free slots for " + vehicleType + " on Floor " + floorNumber + ": " + freeSlotsCount);
        }
    }
    private void displayFreeSlots(VehicleType vehicleType) {
        for (int floorNumber = 1; floorNumber <= parkingLot.getNumberOfFloors(); floorNumber++) {
            String freeSlots = parkingLot.getFreeSlots(floorNumber-1, vehicleType);
            displayMessage("Free slots for " + vehicleType + " on Floor " + floorNumber + ": " + freeSlots);
        }
    }
    private void displayOccupiedSlots(VehicleType vehicleType) {
        for (int floorNumber = 1; floorNumber <= parkingLot.getNumberOfFloors(); floorNumber++) {
            String occupiedSlots = parkingLot.getOccupiedSlots(floorNumber-1, vehicleType);
            displayMessage("Occupied slots for " + vehicleType + " on Floor " + floorNumber + ": " + occupiedSlots);
        }
    }
}
