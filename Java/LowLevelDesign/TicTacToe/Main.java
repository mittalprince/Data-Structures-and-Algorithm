package TicTacToe;

public class Main {
    TicTacToeGame game = new TicTacToeGame();
    game.initializeGame();
    System.out.println("game winner is: " + game.startGame());
}