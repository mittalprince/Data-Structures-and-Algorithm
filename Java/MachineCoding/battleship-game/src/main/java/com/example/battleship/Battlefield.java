package com.example.battleship;
import java.util.ArrayList;
import java.util.List;

public class Battlefield {
    private final int size;
    private final char[][] grid;
    private final List<Ship> ships;

    public Battlefield(int size){
        this.size = size;
        this.grid = new char[size][size];
        this.ships = new ArrayList<>();
    }
    public int getSize(){
        return size;
    }

    public void placeShip(Ship ship, char playerId){
        ships.add(ship);
        for(int i=ship.getX(); i<ship.getX() + ship.getSize(); i++){
            for(int j=ship.getY(); j<ship.getY()+ship.getSize(); j++){
                grid[i][j] = playerId;
            }
        }
    }

    public boolean isHit(int x, int y){
        for(Ship ship: ships){
            if(ship.occupies(x,y)) return true;
        }
        return false;
    }
    public void markHit(int x, int y){
        grid[x][y] = 'X'; // Mark hit location with 'X'
    }
    public void removeShip(Ship ship) {
        ships.remove(ship);
    }

    public void removeShips(){
        ships.clear();
    }
    public List<Ship> getShips() {
        return ships;
    }
}
