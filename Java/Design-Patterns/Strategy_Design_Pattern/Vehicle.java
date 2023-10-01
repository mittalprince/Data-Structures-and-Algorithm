import Strategy.DriveStrategy;

public class Vehicle {
    DriveStrategy driveObj;

    public Vehicle(DriveStrategy obj){
        this.driveObj = obj;
    }
    public drive(){
        driveObj.update();
    }

}