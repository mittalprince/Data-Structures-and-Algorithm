package com.example.battleship;
import java.util.Scanner;
public class Main {
    public static void main(String args[]){
        Scanner scanner = new Scanner(System.in);
        System.out.println("Enter the size of the battlefield (N): ");
        int gridSize = scanner.nextInt();

        GameController gameController = GameController.getInstance(gridSize);
        gameController.initializeFleet();
        gameController.startGame();
    }
}
