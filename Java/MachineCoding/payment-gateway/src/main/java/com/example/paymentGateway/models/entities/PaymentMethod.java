package com.example.paymentGateway.models.entities;

public abstract class PaymentMethod {
    protected PaymentMode mode;

    public PaymentMethod(PaymentMode mode) {
        this.mode = mode;
    }

    public PaymentMode getMode() {
        return mode;
    }
}
