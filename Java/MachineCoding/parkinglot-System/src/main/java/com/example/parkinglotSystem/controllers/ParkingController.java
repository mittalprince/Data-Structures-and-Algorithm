package com.example.parkinglotSystem.controllers;

import com.example.parkinglotSystem.models.entities.ParkingLot;
import com.example.parkinglotSystem.models.entities.Ticket;
import com.example.parkinglotSystem.models.enums.ActionType;
import com.example.parkinglotSystem.models.enums.DisplayType;
import com.example.parkinglotSystem.models.enums.VehicleType;
import com.example.parkinglotSystem.models.vehicle.Vehicle;
import com.example.parkinglotSystem.services.DisplayService;
import com.example.parkinglotSystem.services.ParkingService;
import com.example.parkinglotSystem.strategy.FirstAvailableStrategy;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;
import java.util.Vector;
import java.util.concurrent.ConcurrentHashMap;

public class ParkingController {
    private ParkingService parkingService;
    private DisplayService displayService;
    private Map<String, Ticket> ticketMap = new ConcurrentHashMap<>();

    public ParkingController(){}

    public ParkingController(ParkingLot parkingLot){
        this.parkingService = new ParkingService(parkingLot);
        this.displayService = new DisplayService(parkingLot);
    }

    public void run(String filename) throws FileNotFoundException {
        Scanner scanner = new Scanner(new File(filename));
        String command;
        while (!(command = scanner.nextLine()).equals("exit")) {
            parseCommand(command);
        }
    }
    private void handleCreateParkingLot(String[] parts){
        String parkingLotId = parts[1];
        int noOfFloors = Integer.parseInt(parts[2]);
        int noOfSlotsPerFloor = Integer.parseInt(parts[3]);
        ParkingLot parkingLot = ParkingLot.getInstance(parkingLotId, noOfFloors, noOfSlotsPerFloor, new FirstAvailableStrategy());
        this.parkingService = new ParkingService(parkingLot);
        this.displayService = new DisplayService(parkingLot);
        displayService.displayMessage("Created parking lot with "+ noOfFloors +  " floors and "+ noOfSlotsPerFloor + " slots per floor");
    }
    private void handleParkVehicle(String[] parts) throws Exception {
        VehicleType vehicleType = VehicleType.valueOf(parts[1].toUpperCase());
        String registrationNumber = parts[2];
        String color = parts[3];
        Ticket ticket = parkingService.parkVehicle(vehicleType, registrationNumber, color);
        if(ticket != null)  {
            displayService.displayMessage("Parked vehicle. Ticket ID: " + ticket.getId());
            ticketMap.put(ticket.getId(), ticket);
        }
        else displayService.displayMessage("Parking Lot Full");
    }
    private void handleUnParkVehicle(String[] parts) throws Exception {
        String ticketId = parts[1];
        if(ticketMap.containsKey(ticketId)){
            parkingService.unParkVehicle(ticketMap.get(ticketId));
            Vehicle vehicle = ticketMap.get(ticketId).getVehicle();
            displayService.displayMessage("Unparked vehicle with Registration Number: " + vehicle.getRegistrationNumber() + " and Color: " + vehicle.getColor());
            ticketMap.remove(ticketId);
        } else{
            displayService.displayMessage("Invalid Ticket");
        }
    }

    private void handleDisplay(String[] parts){
        DisplayType displayType = DisplayType.valueOf(parts[1].toUpperCase());
        VehicleType vehicleType = VehicleType.valueOf(parts[2].toUpperCase());
        displayService.display(displayType,vehicleType);
    }

    private void parseCommand(String command){
        String[] parts = command.trim().split(" ");
        if (parts.length == 0) {
            displayService.displayMessage("Invalid command. Please try again.");
            return;
        }
        String action = parts[0];
        ActionType actionType = ActionType.valueOf(action.toUpperCase());
        try{
            switch (actionType){
                case CREATE_PARKING_LOT:
                    if (parts.length != 4) {
                        displayService.displayMessage("Invalid command format. Use: create_parking_lot <ParkingLotID> <NoOfFloors> <NoOfSlotsPerFloor>");
                        return;
                    }
                    this.handleCreateParkingLot(parts);
                    break;
                case PARK_VEHICLE:
                    if (parts.length != 4) {
                        displayService.displayMessage("Invalid command format. Use: park <VehicleType> <RegistrationNumber> <Color>");
                        return;
                    }
                    this.handleParkVehicle(parts);
                    break;
                case UNPARK_VEHICLE:
                    if (parts.length != 2) {
                        displayService.displayMessage("Invalid command format. Use: unpark <TicketId>");
                        return;
                    }
                    this.handleUnParkVehicle(parts);
                    break;
                case DISPLAY:
                    if (parts.length != 3) {
                        displayService.displayMessage("Invalid command format. Use: display <DisplayType>");
                        return;
                    }
                    handleDisplay(parts);
                    break;
                case EXIT:
                    displayService.displayMessage("Exiting...");
                    break;

                default:
                    displayService.displayMessage("Unknown command. Please try again.");
                    break;
            }
        } catch (Exception e) {
            displayService.displayMessage("Invalid arguments provided. Please try again." + e.getMessage());
        }
    }
}
