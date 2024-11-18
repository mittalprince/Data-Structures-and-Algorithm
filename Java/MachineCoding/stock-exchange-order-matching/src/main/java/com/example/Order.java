package com.example;

public class Order implements Comparable<Order> {
    private String id;
    private String time;
    private String stock;
    private StockType type;
    private double price;
    private int quantity;

    public Order(String id, String time, String stock, StockType type, double price, int quantity) {
        this.id = id;
        this.time = time;
        this.stock = stock;
        this.type = type;
        this.price = price;
        this.quantity = quantity;
    }
    @Override
    public int compareTo(Order o){
        if(this.type.equals(StockType.BUY)){
            return o.price == this.price ? this.time.compareTo(o.time) : Double.compare(o.price, this.price);
        } else{
            return this.price == o.price ? this.time.compareTo(o.time) : Double.compare(this.price, o.price);
        }
    }

    public StockType getType() {
        return type;
    }
    public int getQuantity() {
        return quantity;
    }
    public void setQuantity(int quantity) {
        this.quantity = quantity;
    }

    public double getPrice() {
        return price;
    }
    public String getId() {
        return id;
    }
}
