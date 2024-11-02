package com.example.paymentGateway.models.factory;

import com.example.paymentGateway.models.processor.CardProcessor;
import com.example.paymentGateway.models.processor.PaymentProcessor;
import com.example.paymentGateway.models.processor.UPIProcessor;
import com.example.paymentGateway.models.entities.PaymentMode;

public class PaymentProcessorFactory {
    public static PaymentProcessor getProcessor(PaymentMode mode) {
        switch (mode) {
            case UPI:
                return new UPIProcessor();
            case CARD:
                return new CardProcessor();
            default:
                throw new IllegalArgumentException("Unsupported payment mode");
        }
    }
}
