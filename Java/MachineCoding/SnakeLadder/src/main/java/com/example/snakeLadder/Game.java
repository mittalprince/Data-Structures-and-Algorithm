package com.example.snakeLadder;

import java.util.Deque;
import java.util.LinkedList;
import java.util.List;

public class Game {
    private Board board;
    private Dice dice;
    Deque<Player> playersList = new LinkedList<>();
    Player winner = null;

    public Game(){
        initializeGame();
    }
    public void startGame(){
        while(winner==null){
            Player playerTurn = findPlayerTurn();
            System.out.println("player turn is:" + playerTurn.getName() + " current position is: " + playerTurn.getCurrentPosition());
            int diceNumber = dice.diceRoll();
            int playerNewPosition = playerTurn.getCurrentPosition() + diceNumber;
            playerNewPosition = jumpCheck(playerNewPosition);
            playerTurn.setCurrentPosition(playerNewPosition);
            System.out.println("player turn is:" + playerTurn.getName() + " new Position is: " + playerNewPosition);
            if(playerNewPosition >= board.getBoardSize()){
                winner = playerTurn;
            }
        }
        System.out.println("WINNER IS:" + winner.getName());
    }

    private void initializeGame(){
        board = new Board(8, 5, 6);
        dice = new Dice(1);
        winner = null;
        addPlayers();
    }
    private void addPlayers(){
        Player player1 = new Player("p1", 0);
        Player player2 = new Player("p2", 0);
        playersList.add(player1);
        playersList.add(player2);
    }
    private Player findPlayerTurn(){
        Player playerTurn = playersList.removeFirst();
        playersList.addLast(playerTurn);
        return playerTurn;
    }
    private int jumpCheck(int playerNewPosition){
        if(playerNewPosition >= board.getBoardSize())return playerNewPosition;
        Cell cell = board.getCell(playerNewPosition);
        if(cell.getJump() != null && cell.getJump().getStart() == playerNewPosition){
            String jumpBy = (cell.getJump().getStart() < cell.getJump().getEnd()) ? "Ladder" : "Snake";
            System.out.println("jump done by: " + jumpBy);
            return cell.getJump().getEnd();
        }
        return playerNewPosition;
    }
}
