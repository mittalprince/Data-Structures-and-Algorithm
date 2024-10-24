package com.example.battleship;
import java.util.Scanner;

public class GameController {
    private static GameController instance;
    private final Player playerA;
    private final Player playerB;
    private final int gridSize;

    private GameController(int gridSize){
        this.gridSize = gridSize;
        playerA = new Player("PlayerA", new Battlefield(gridSize), new RandomFiringStrategy());
        playerB = new Player("PlayerB", new Battlefield(gridSize), new RandomFiringStrategy());
    }

    public static GameController getInstance(int gridSize){
        if(instance == null){
            instance = new GameController(gridSize);
        }
        return instance;
    }

    public void initializeFleet(){
        Scanner scanner = new Scanner(System.in);
        System.out.println("Enter number of ships for each player:");
        int shipCount = scanner.nextInt();

        for(int i=1; i<=shipCount; i++){
            System.out.println("Enter size and coordinates (x, y) for PlayerA's Ship" + i + ":");
            int size = scanner.nextInt();
            int x = scanner.nextInt();
            int y = scanner.nextInt();
            playerA.addShip(new Ship("A-SH" + i, size, x, y));

            System.out.println("Enter size and coordinates (x, y) for PlayerB's Ship" + i + ":");
            size = scanner.nextInt();
            x = scanner.nextInt();
            y = scanner.nextInt();
            playerB.addShip(new Ship("B-SH" + i, size, x, y));
        }
    }

    public void startGame(){
        boolean playerTurn = true;
        while (!playerA.hasLost() && !playerB.hasLost()){
            if(playerTurn){
                playerA.fireMissile(playerB);
            } else {
                playerB.fireMissile(playerA);
            }
            playerTurn = !playerTurn;
        }

        if (playerA.hasLost()) {
            System.out.println("PlayerB wins!");
        } else {
            System.out.println("PlayerA wins!");
        }
    }

    public Player getPlayerA(){
        return playerA;
    }
    public Player getPlayerB(){
        return playerB;
    }
}
