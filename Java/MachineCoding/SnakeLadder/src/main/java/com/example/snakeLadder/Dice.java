package com.example.snakeLadder;
import  java.util.concurrent.ThreadLocalRandom;

public class Dice {
    private final int diceCount;
    private final int min=1;
    private final int max=6;

    public Dice(int diceCount){
        this.diceCount = diceCount;
    }
    public int diceRoll(){
        int totalSum=0;
        int diceUsed=0;
        while(diceUsed<diceCount){
            totalSum += ThreadLocalRandom.current().nextInt(min,max);
            diceUsed++;
        }
        return totalSum;
    }
}
