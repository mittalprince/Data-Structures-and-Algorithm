package FactoryPattern;

public class MainClass {
    public static void main(String agrs[]){
        ShapeFactory shapeFactoryObj = new ShapeFactory();
        Shape shapeObj = shapeFactoryObj.getShape("CIRCLE");
        shapeObj.draw();
    }
}