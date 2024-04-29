package LowLevelDesign.LLDSnakeLadder;

import java.util.Deque;
import java.util.LinkedList;

public class Game {
    Board board;
    Dice dice;
    Dequeue<Player> playersList = new LinkedList<>();
    Player winner = null;

    Game(){
        initializeGame();
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

    void startGame(){
        while(winner != null){
            Player playerTurn = findPlayerTurn();
            System.out.println("player turn is:" + playerTurn.id + " current position is: " + playerTurn.currentPosition);

            int diceNumber = dice.rollDice();
            int playerNewPosition = player.currentPosition + diceNumber;
            playerNewPosition = jumpCheck(playerNewPosition);
            playerTurn.currentPosition - playerNewPosition;
            System.out.println("player turn is:" + playerTurn.id + " new Position is: " + playerNewPosition);
            if(playerNewPosition >= board.cells.length * board.cells.length - 1){
                winner = playerTurn;
            }
        }
        System.out.println("WINNER IS:" + winner.id);
    }
    private Player findPlayerTurn(){
        Player playerTurn = playersList.removeFirst();
        playerTurn.addLast(playerTurn);
        return playerTurn;
    }
    private int jumpCheck(int playerNewPosition){
        if(playerNewPosition >= board.cells.length * board.cells.length - 1){
            return playerNewPosition;
        }
        Cell cell = board.getCell(playerNewPosition);
        if(cell.jump !=null && cell.jump.start == playerNewPosition){
            String jumpBy = (cell.jump.start < cell.jump.end) ? "Ladder" : "Snake";
            System.out.println("jump done by: " + jumpBy);
            return cell.jump.end;
        }
        return playerNewPosition;
    }
}