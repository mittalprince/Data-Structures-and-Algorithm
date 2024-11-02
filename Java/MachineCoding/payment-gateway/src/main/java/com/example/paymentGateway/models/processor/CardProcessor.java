package com.example.paymentGateway.models.processor;

import com.example.paymentGateway.models.entities.Card;
import com.example.paymentGateway.models.entities.PaymentMethod;
import com.example.paymentGateway.models.entities.PaymentMode;

public class CardProcessor implements PaymentProcessor {
    @Override
    public boolean validate(PaymentMethod paymentMethod) {
        // Card specific validation
        return paymentMethod instanceof Card && ((Card) paymentMethod).getCvv() != null;
    }

    @Override
    public boolean processTransaction(PaymentMethod paymentMethod) {
        return true;
    }
}
