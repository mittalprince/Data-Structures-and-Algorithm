package com.example.snakeandladder;
import java.util.Map;

public class Board {
    public static final int WINNING_POSITION = 100;
    private final Map<Integer, Integer> snakes;
    private final Map<Integer, Integer> ladders;

    public Board(Map<Integer, Integer> snakes, Map<Integer, Integer> ladders){
        this.snakes = snakes;
        this.ladders = ladders;
    }
    public int calculateNextPosition(int position){
        if(position > WINNING_POSITION)return position;
        while(snakes.containsKey(position) || ladders.containsKey(position)){
            if(snakes.containsKey(position)){
                position = snakes.get(position);
            } else if (ladders.containsKey(position)) {
                position = ladders.get(position);
            }
        }
        return position;
    }
}
