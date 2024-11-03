package com.example.parkinglotSystem.models.entities;

import com.example.parkinglotSystem.factory.ParkingSlotFactory;
import com.example.parkinglotSystem.models.enums.VehicleType;
import com.example.parkinglotSystem.models.vehicle.Vehicle;

import java.util.ArrayList;
import java.util.List;
import java.util.UUID;

public class Floor {
    private final int floorNumber;
    private final List<ParkingSlot> slots;

    public Floor(int floorNumber, int numSlots){
        this.floorNumber = floorNumber;
        this.slots = new ArrayList<>();
        // Slot type initialization: 1st is Truck, next 2 are Bike, others are Car
        for (int i = 1; i <= numSlots; i++) {
            slots.add(ParkingSlotFactory.createParkingSlot(i, i == 1 ? VehicleType.TRUCK : (i <= 3 ? VehicleType.BIKE : VehicleType.CAR)));
        }
    }

    public int getFloorNumber() { return floorNumber; }
    public List<ParkingSlot> getSlots() { return slots; }
    public Ticket parkVehicle(String parkingLotId, Vehicle vehicle){
        for(ParkingSlot slot: slots){
            if(slot.isAvailableForPark(vehicle.getType())){
                slot.park(vehicle);
                return generateTicket(parkingLotId, vehicle, slot.getSlotNumber());
            }
        }
        return null;
    }
    public void unParkVehicle(Ticket ticket){
        ParkingSlot slot = slots.get(ticket.getSlotNumber()-1);
        slot.unPark();
    }
    private Ticket generateTicket(String parkingLotId, Vehicle vehicle, int slotNumber){
        return new Ticket(parkingLotId, vehicle, floorNumber, slotNumber);
    }

    public int getFreeSlotsCount(VehicleType vehicleType){
        int freeSlots = 0;
        for(ParkingSlot slot: slots){
            freeSlots += slot.isAvailableForPark(vehicleType) ? 1 : 0;
        }
        return freeSlots;
    }

    public String getFreeSlots(VehicleType vehicleType) {
        List<String> freeSlots = new ArrayList<>();
        for (ParkingSlot slot : slots) {
            if (slot.isAvailableForPark(vehicleType)) {
                freeSlots.add(String.valueOf(slot.getSlotNumber()));
            }
        }
        return String.join(",", freeSlots);
//        return String.join(",", freeSlots.stream().map(String::valueOf).toArray(String[]::new));
    }

    public String getOccupiedSlots(VehicleType vehicleType) {
        List<Integer> occupiedSlots = new ArrayList<>();
        for (ParkingSlot slot : slots) {
            if (slot.isOccupiedSlot(vehicleType)) {
                occupiedSlots.add(slot.getSlotNumber());
            }
        }
        return String.join(",", occupiedSlots.stream().map(String::valueOf).toArray(String[]::new));
    }
}
