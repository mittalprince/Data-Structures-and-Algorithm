package com.example;

import com.example.battleship.Battlefield;
import com.example.battleship.Ship;
import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class BattlefieldTest {

    private Battlefield battlefield;

    @BeforeEach
    void setUp() {
        battlefield = new Battlefield(10);
    }

    @Test
    void testShipPlacement() {
        Ship ship = new Ship("A-SH1", 3, 2, 2);
        battlefield.placeShip(ship, 'A');

        assertTrue(battlefield.isHit(2, 2));
        assertTrue(battlefield.isHit(3, 3));
        assertFalse(battlefield.isHit(5, 5));  // Should not be hit outside ship boundaries
    }

    @Test
    void testHitAndMiss() {
        Ship ship = new Ship("B-SH2", 2, 5, 5);
        battlefield.placeShip(ship, 'B');

        assertTrue(battlefield.isHit(5, 5));
        assertFalse(battlefield.isHit(7, 7)); // Miss outside of ship boundary
    }

    @Test
    void testRemoveShip() {
        Ship ship = new Ship("A-SH1", 3, 2, 2);
        battlefield.placeShip(ship, 'A');
        battlefield.removeShip(ship);

        assertFalse(battlefield.isHit(2, 2)); // Should no longer be a hit after removal
    }
}
