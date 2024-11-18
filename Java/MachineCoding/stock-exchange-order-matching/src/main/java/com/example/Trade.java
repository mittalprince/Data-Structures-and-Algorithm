package com.example;

public class Trade {
    private String buyOrderId;
    private String sellOrderId;
    private double sellPrice;
    private int quantity;

    public Trade(String buyOrderId, String sellOrderId, double sellPrice, int quantity) {
        this.buyOrderId = buyOrderId;
        this.sellOrderId = sellOrderId;
        this.sellPrice = sellPrice;
        this.quantity = quantity;
    }

    @Override
    public String toString() {
        return String.format("%s %.2f %d %s", buyOrderId, sellPrice, quantity, sellOrderId);
    }
}
