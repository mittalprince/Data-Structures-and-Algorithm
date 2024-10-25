package com.example.snakeandladder;
import java.io.File;
import java.io.FileNotFoundException;
import java.util.*;

public class Main {
    public static void main(String args[]) throws FileNotFoundException {
        if(args.length != 1){
            System.out.println("Please provide a valid input file.");
            return;
        }
        Scanner scanner = new Scanner(new File(args[0]));

        int nuSnakes = scanner.nextInt();
        Map<Integer, Integer> snakes = new HashMap<>();
        for(int i=0; i<nuSnakes; i++){
            snakes.put(scanner.nextInt(), scanner.nextInt());
        }

        int numLadders = scanner.nextInt();
        Map<Integer, Integer> ladders = new HashMap<>();
        for (int i = 0; i < numLadders; i++) {
            ladders.put(scanner.nextInt(), scanner.nextInt());
        }

        int numPlayers = scanner.nextInt();
        List<Player> players = new ArrayList<>();
        for (int i = 0; i < numPlayers; i++) {
            players.add(new Player(scanner.next()));
        }

        Board board = new Board(snakes, ladders);
        Game game = new Game(board, players);
        game.startGame();
    }
}
