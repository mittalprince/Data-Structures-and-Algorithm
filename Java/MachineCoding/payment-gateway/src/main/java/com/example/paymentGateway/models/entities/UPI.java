package com.example.paymentGateway.models.entities;

public class UPI extends PaymentMethod {
    private String vpa;

    public UPI(String vpa) {
        super(PaymentMode.UPI);
        this.vpa = vpa;
    }

    public String getVpa() {
        return vpa;
    }
}
