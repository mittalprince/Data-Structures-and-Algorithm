package com.example.paymentGateway.models.entities;

public class Card extends PaymentMethod {
    private final String cardNumber;
    private final String expiry;
    private final String cvv;

    public Card(String cardNumber, String expiry, String cvv) {
        super(PaymentMode.CARD);
        this.cardNumber = cardNumber;
        this.expiry = expiry;
        this.cvv = cvv;
    }

    public String getCardNumber() {
        return cardNumber;
    }

    public String getExpiry() {
        return expiry;
    }

    public String getCvv() {
        return cvv;
    }
}
