package com.example.paymentGateway.models.entities;

import java.util.Set;

public class Client {
    private final String name;
    private Set<PaymentMode> supportedPaymentMethods;

    public Client(String name, Set<PaymentMode> supportedPaymentMethods) {
        this.name = name;
        this.supportedPaymentMethods = supportedPaymentMethods;
    }

    public String getName() {return name;}
    public Set<PaymentMode> getSupportedPaymentMethods() {return supportedPaymentMethods; }
    public void addPaymentMethod(PaymentMode paymentMethod){
        supportedPaymentMethods.add(paymentMethod);
    }
    public void removePaymentMethod(PaymentMode paymentMethod) {
        supportedPaymentMethods.remove(paymentMethod);
    }
    public boolean supportPaymentMethod(PaymentMode paymentMethod){
        return supportedPaymentMethods.contains(paymentMethod);
    }
}
