package com.example.parkinglotSystem.factory;

import com.example.parkinglotSystem.models.entities.ParkingLot;
import com.example.parkinglotSystem.models.entities.ParkingSlot;
import com.example.parkinglotSystem.models.enums.VehicleType;

public class ParkingSlotFactory {
    public static ParkingSlot createParkingSlot(int slotNumber, VehicleType type){
        return new ParkingSlot(slotNumber, type);
    }
}
