package com.example;

import com.example.battleship.GameController;
import com.example.battleship.Player;
import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class GameControllerTest {

    private GameController gameController;

    @BeforeEach
    void setUp() {
        gameController = GameController.getInstance(10);
    }

    @Test
    void testGameInitialization() {
        assertNotNull(gameController);

        // Check Singleton behavior
        GameController anotherController = GameController.getInstance(10);
        assertSame(gameController, anotherController);  // Both references should point to the same instance
    }

//    @Test
//    void testFleetInitialization() {
//        gameController.initializeFleet();
//
//        Player playerA = gameController.getPlayerA();
//        assertFalse(playerA.getBattlefield().getShips().isEmpty());  // Fleet must be initialized
//    }

//    @Test
//    void testGameFlow() {
//        gameController.initializeFleet();
//        gameController.startGame();
//
//        // Check whether a winner is declared at the end
//        assertTrue(gameController.getPlayerA().hasLost() || gameController.getPlayerB().hasLost());
//    }

}
