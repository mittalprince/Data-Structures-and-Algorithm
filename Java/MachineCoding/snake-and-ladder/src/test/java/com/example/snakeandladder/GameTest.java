package com.example.snakeandladder;

import com.example.snakeandladder.*;
import org.junit.jupiter.api.Test;
import static org.junit.jupiter.api.Assertions.assertEquals;
import java.util.*;

class GameTest{
    @Test
    void testGameEndsWhenPlayerReaches100(){
        Map<Integer, Integer> snakes = new HashMap<>();
        Map<Integer, Integer> ladders = new HashMap<>();
        Board board = new Board(snakes, ladders);
        Player player1 = new Player("Alice");
        Player player2 = new Player("Bob");
        Game game = new Game(board, List.of(player1, player2));
        game.startGame();
        player1.setPosition(Board.WINNING_POSITION);
        assertEquals(Board.WINNING_POSITION, player1.getPosition());
    }
}