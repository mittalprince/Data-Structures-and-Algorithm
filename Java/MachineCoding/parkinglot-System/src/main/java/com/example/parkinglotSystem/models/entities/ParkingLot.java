package com.example.parkinglotSystem.models.entities;

import com.example.parkinglotSystem.models.enums.VehicleType;
import com.example.parkinglotSystem.models.vehicle.Vehicle;
import com.example.parkinglotSystem.strategy.ParkingStrategy;

import java.util.ArrayList;
import java.util.List;

public class ParkingLot {
    private final String id;
    private final List<Floor> floors;
    private ParkingStrategy parkingStrategy;
    private static ParkingLot parkingLot;

    private ParkingLot(String id, int numFloors, int numSlotsPerFloor, ParkingStrategy parkingStrategy) {
        this.id = id;
        this.floors = new ArrayList<>();
        for(int i=1; i<= numFloors; i++){
            floors.add(new Floor(i, numSlotsPerFloor));
        }
        this.parkingStrategy = parkingStrategy;
    }
    public static ParkingLot getInstance(String id, int numFloors, int numSlotsPerFloor, ParkingStrategy parkingStrategy){
        if(parkingLot == null){
            synchronized (ParkingLot.class){
                if(parkingLot == null){
                    parkingLot = new ParkingLot(id, numFloors, numSlotsPerFloor, parkingStrategy);
                }
            }
        }
        return parkingLot;
    }

    public String getId() { return id; }
    public List<Floor> getFloors() { return floors; }
    public void addFloor() {
        // Optional: Method to add a floor dynamically
    }
    public void setParkingStrategy(ParkingStrategy strategy) {
        this.parkingStrategy = strategy;
    }
    public Ticket parkVehicle(Vehicle vehicle){
        // pass pricing strategy
        return parkingStrategy.park(this, vehicle);
    }
    public void unParkVehicle(Ticket ticket) throws Exception{
        for(Floor floor: floors){
            if(floor.getFloorNumber() == ticket.getFloorNumber()){
                floor.unParkVehicle(ticket);
                return;
            }
        }
        throw new IllegalArgumentException("Invalid Ticket");
    }
    public int getNumberOfFloors(){
        return floors.size();
    }
    public int getFreeSlotsCount(int floorNumber, VehicleType vehicleType){
        return floors.get(floorNumber).getFreeSlotsCount(vehicleType);
    }
    public String getFreeSlots(int floorNumber, VehicleType vehicleType){
        return floors.get(floorNumber).getFreeSlots(vehicleType);
    }
    public String getOccupiedSlots(int floorNumber, VehicleType vehicleType){
        return floors.get(floorNumber).getOccupiedSlots(vehicleType);
    }
}
