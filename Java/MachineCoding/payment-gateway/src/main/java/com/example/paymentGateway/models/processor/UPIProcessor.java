package com.example.paymentGateway.models.processor;

import com.example.paymentGateway.models.entities.PaymentMethod;
import com.example.paymentGateway.models.entities.PaymentMode;
import com.example.paymentGateway.models.entities.UPI;

public class UPIProcessor implements PaymentProcessor {
    @Override
    public boolean validate(PaymentMethod paymentMethod) {
        // UPI specific validation
        return paymentMethod instanceof UPI && ((UPI) paymentMethod).getVpa() != null;
    }

    @Override
    public boolean processTransaction(PaymentMethod paymentMethod) {
        return true;
    }
}