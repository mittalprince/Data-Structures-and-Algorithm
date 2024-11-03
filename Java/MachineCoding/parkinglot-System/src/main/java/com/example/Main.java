package com.example;

import com.example.parkinglotSystem.controllers.ParkingController;

import java.io.FileNotFoundException;

public class Main {
    public static void main(String[] args) {
        if(args.length != 1){
            System.out.println("Please provide a valid input file.");
            return;
        }
        try {
            ParkingController parkingController = new ParkingController();
            parkingController.run(args[0]);
        } catch (FileNotFoundException e){
            System.out.println(e.getMessage());
        }
    }
}