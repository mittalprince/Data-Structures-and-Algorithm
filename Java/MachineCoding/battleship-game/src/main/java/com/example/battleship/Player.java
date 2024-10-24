package com.example.battleship;
import java.util.ArrayList;
import java.util.List;
import java.util.HashSet;
import java.util.Set;

public class Player {
    private final String name;
    private final Battlefield battlefield;
    private final Set<String> firedCoordinates;
    private final FiringStrategy firingStrategy;
    private List<Ship> fleet;

    public Player(String name, Battlefield battlefield, FiringStrategy firingStrategy) {
        this.name = name;
        this.battlefield = battlefield;
        this.firingStrategy = firingStrategy;
        this.firedCoordinates = new HashSet<>();
        this.fleet = new ArrayList<>();
    }

    public void addShip(Ship ship){
        fleet.add(ship);
        battlefield.placeShip(ship, name.charAt(0));
    }
    public void removePlayerShips(){
        fleet.clear();
        battlefield.removeShips();
    }
    public boolean hasLost(){
        return fleet.isEmpty();
    }
    public Battlefield getBattlefield() {
        return battlefield;
    }
    public boolean fireMissile(Player opponent){
        int[] coordinate = firingStrategy.fireMissile(this, opponent);
        int x = coordinate[0];
        int y = coordinate[1];

        // Record the coordinates
        firedCoordinates.add(x + "," + y);
        if(opponent.getBattlefield().isHit(x,y)){
            opponent.getBattlefield().markHit(x,y);
            System.out.println(name + " fires at (" + x + ", " + y + "): Hit!");
            return true;
        } else{
            System.out.println(name + " fires at (" + x + ", " + y + "): Miss.");
            return false;
        }
    }
    public boolean hasFiredAt(int x, int y) {
        return firedCoordinates.contains(x + "," + y);
    }
}
