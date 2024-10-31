package com.example.paymentGateway.models.processor;

import com.example.paymentGateway.models.entities.PaymentMethod;
import com.example.paymentGateway.models.entities.PaymentMode;

public interface PaymentProcessor {
    boolean validate(PaymentMethod paymentMethod);
    boolean processTransaction(PaymentMethod paymentMethod);
}