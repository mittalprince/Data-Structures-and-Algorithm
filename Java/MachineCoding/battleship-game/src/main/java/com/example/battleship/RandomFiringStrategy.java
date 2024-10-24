package com.example.battleship;
import java.util.Random;

public class RandomFiringStrategy implements FiringStrategy {
    @Override
    public int[] fireMissile(Player player, Player opponent){
        Random random = new Random();
        int gridSize = opponent.getBattlefield().getSize();
        int x,y;
        // Fire at a random coordinate
        do{
            x = random.nextInt(gridSize);
            y = random.nextInt(gridSize);
        } while (player.hasFiredAt(x,y));
        return new int[] {x,y};
    }
}
