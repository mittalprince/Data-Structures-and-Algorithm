package org.example.vendingMachine;

public class Item {
    private char type;
    private int price;

    public Item(char type, int price) {
        this.type = type;
        this.price = price;
    }

    public char getType() {
        return type;
    }

    public void setType(char type) {
        this.type = type;
    }

    public int getPrice() {
        return price;
    }

    public void setPrice(int price) {
        this.price = price;
    }
    @Override
    public String toString() {
        return type + "=" + price;
    }
}