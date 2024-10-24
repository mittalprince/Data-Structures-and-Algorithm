package com.example.battleship;

public class Ship {
    private final String id;
    private final int size;
    private final int x;
    private final int y;

    public Ship(String id, int size, int x, int y) {
        this.id = id;
        this.size = size;
        this.x = x;
        this.y = y;
    }
    public String getId() {
        return id;
    }
    public int getX() {
        return x;
    }
    public int getY() {
        return y;
    }

    public int getSize() {
        return size;
    }
    public boolean occupies(int x, int y){
        // Check if (x, y) falls within the boundaries of this ship
        return x >= this.x && x < this.x + size && y >= this.y && y < this.y + size;
    }
}
