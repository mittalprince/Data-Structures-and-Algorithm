import Strategy.SportsDriveStrategy;

public class MormalVehicle extends Vehicle{
    public MormalVehicle(){
        super(new NormalDriveStrategy());
    }
}