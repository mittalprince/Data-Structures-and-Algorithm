package org.example.vendingMachine;

import java.io.FileNotFoundException;

public class VendingMachineController {
    public static void main(String agrs[]) throws FileNotFoundException {
        if(agrs.length != 1){
            System.out.println("Please provide a valid input file.");
            return;
        }
        CommandParser commandParser = new CommandParser();
        commandParser.processCommandFromFile(agrs[0]);
    }
}
