package com.example.communicationSystem;
public class Main {
    public static void main(String[] args) throws Exception {
        if(args.length != 1){
            System.out.println("Please provide a valid input file.");
            return;
        }
        CommandParser commandParser = new CommandParser();
        commandParser.processCommandFromFile(args[0]);
    }
}
