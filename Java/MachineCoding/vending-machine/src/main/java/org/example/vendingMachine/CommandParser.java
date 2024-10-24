package org.example.vendingMachine;
import java.util.*;
import java.io.*;

public class CommandParser {
    private VendingMachine vendingMachine;

    public void executeCommand(String command){
        String[] token = command.split(" ");
        switch (token[0]){
            case Contstant.INIT_MACHINE:
                int capacity = Integer.parseInt(token[1]);
                vendingMachine = VendingMachine.getInstance(capacity);
                System.out.println("Initialized machine with capacity " + capacity);
                break;
            case Contstant.SET_PRICES:
                int[] prices = new int[token.length-1];
                for(int i=1; i<token.length; i++){
                    prices[i-1] = Integer.parseInt(token[i]);
                }
                vendingMachine.setPrices(prices);
                break;
            case Contstant.INSERT:
                char type = token[1].charAt(0);
                vendingMachine.insertItem(type);
                break;
            case Contstant.GET:
                int slotIndex = Integer.parseInt(token[1]);
                int payment = Integer.parseInt(token[3]);
                vendingMachine.get(slotIndex, payment);
                break;
            case Contstant.STATUS:
                vendingMachine.status();
                break;
            default:
                System.out.println("Invalid Command");
                break;
        }
    }

    public void processCommandFromFile(String filename) throws FileNotFoundException {
        Scanner scanner = new Scanner(new File(filename));
        while (scanner.hasNextLine()){
            String command = scanner.nextLine();
            executeCommand(command);
        }
        scanner.close();
    }
}
