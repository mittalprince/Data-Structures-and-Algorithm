package com.example.paymentGateway.models.entities;

public class Transaction {
    private String clientId;
    private PaymentMethod paymentMethod;
    private boolean isCritical;

    public Transaction(String clientId, PaymentMethod paymentMethod, boolean isCritical) {
        this.clientId = clientId;
        this.paymentMethod = paymentMethod;
        this.isCritical = isCritical;
    }

    public String getClientId() {
        return clientId;
    }

    public void setClientId(String clientId) {
        this.clientId = clientId;
    }

    public PaymentMethod getPaymentMethod() {
        return paymentMethod;
    }

    public void setPaymentMethod(PaymentMethod paymentMethod) {
        this.paymentMethod = paymentMethod;
    }

    public boolean isCritical() {
        return isCritical;
    }

    public void setCritical(boolean critical) {
        isCritical = critical;
    }
}
