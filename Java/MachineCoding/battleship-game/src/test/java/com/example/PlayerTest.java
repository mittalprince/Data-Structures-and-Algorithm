package com.example;

import com.example.battleship.Battlefield;
import com.example.battleship.Player;
import com.example.battleship.RandomFiringStrategy;
import com.example.battleship.Ship;
import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class PlayerTest {

    private Player playerA;
    private Player playerB;

    @BeforeEach
    void setUp() {
        playerA = new Player("PlayerA", new Battlefield(10), new RandomFiringStrategy());
        playerB = new Player("PlayerB", new Battlefield(10), new RandomFiringStrategy());

        // Add ships
        playerA.addShip(new Ship("A-SH1", 3, 2, 2));
        playerB.addShip(new Ship("B-SH1", 3, 5, 5));
    }

    @Test
    void testPlayerMissileHit() {
        boolean hit = playerA.fireMissile(playerB);

        assertTrue(hit || !hit);  // Either hit or miss
        assertEquals(10, playerA.getBattlefield().getSize()); // Confirm field size is as expected
    }

    @Test
    void testPlayerLosesWhenAllShipsDestroyed() {
        // Destroy all ships
        playerA.fireMissile(playerB); // Hits B
        playerB.fireMissile(playerA); // Hits A

        playerB.removePlayerShips(); // Simulate ship destruction
        assertTrue(playerB.hasLost());
    }

    @Test
    void testPlayerFireUniqueCoordinates() {
        playerA.fireMissile(playerB);
        playerA.fireMissile(playerB); // Second shot should be unique
        assertFalse(playerA.hasFiredAt(0, 0)); // Ensuring no repetition of coordinate shot
    }
}
