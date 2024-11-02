package com.example;

import com.example.paymentGateway.controllers.PaymentController;

public class Main {
    public static void main(String[] args) {
        PaymentController paymentController = new PaymentController();
        paymentController.initializeSystem();
//        paymentController.run();
    }
}