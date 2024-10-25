package com.example.snakeandladder;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;

public class Game {
    private Board board;
    private List<Player> players;
    private Queue<Player> turnQueue;

    public Game(Board board, List<Player> players){
        this.board = board;
        this.players = players;
        this.turnQueue = new LinkedList<>(players);
    }

    public void startGame(){
        Dice dice = new Dice();
        while(true){
            Player player = turnQueue.poll();
            int diceValue = dice.roll();
            int initialPosition = player.getPosition();
            int newPosition = board.calculateNextPosition(initialPosition+diceValue);
            System.out.printf("%s rolled a %d and moved from %d to %d%n",
                    player.getName(), diceValue, initialPosition, newPosition);

            player.setPosition(newPosition);
            if(newPosition == Board.WINNING_POSITION){
                System.out.printf("%s wins the game%n", player.getName());
                break;
            }
            turnQueue.add(player);
        }
    }
}
