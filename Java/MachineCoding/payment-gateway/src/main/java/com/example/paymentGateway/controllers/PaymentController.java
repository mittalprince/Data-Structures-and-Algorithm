package com.example.paymentGateway.controllers;

import com.example.paymentGateway.models.router.DefaultBankRouter;
import com.example.paymentGateway.services.ClientService;
import com.example.paymentGateway.services.PaymentService;
import com.example.paymentGateway.views.ConsoleView;

public class PaymentController {
    private final ClientService clientService;
    private final PaymentService paymentService;
    private final ConsoleView consoleView;

    public PaymentController() {
        this.clientService = new ClientService();
        this.paymentService = new PaymentService(new DefaultBankRouter());
        this.consoleView = new ConsoleView();
    }

    public void initializeSystem() {
        // Initialize system with default clients, banks, payment methods, etc.
        clientService.addClient("Flipkart");
        paymentService.initializeBanks();
    }

    public void run() {
        try {
            // Run the controller loop (pseudo code here)
            consoleView.showWelcomeMessage();
            while (true) {
                // Handle user inputs and perform actions
                consoleView.showOptions();
                String option = consoleView.getUserInput();
                switch (option) {
                    case "1":
                        clientService.addClient(consoleView.getClientName());
                        break;
                    case "2":
                        paymentService.processPayment(consoleView.getPaymentDetails());
                        break;
                    default:
                        consoleView.showInvalidOption();
                }
            }
        } catch (Exception e){
            System.out.println(e.getMessage());
        }
    }
}
