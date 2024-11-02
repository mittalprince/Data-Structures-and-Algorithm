package com.example.paymentGateway.views;

import com.example.paymentGateway.models.entities.PaymentMethod;
import com.example.paymentGateway.models.entities.Transaction;
import com.example.paymentGateway.models.entities.UPI;

import java.util.Scanner;

public class ConsoleView {
    private final Scanner scanner = new Scanner(System.in);

    public void showWelcomeMessage() {
        System.out.println("Welcome to the Payment Gateway!");
    }

    public void showOptions() {
        System.out.println("Select an option:");
        System.out.println("1: Add Client");
        System.out.println("2: Process Payment");
    }

    public String getUserInput() {
        return scanner.nextLine();
    }

    public String getClientName() {
        System.out.print("Enter client name: ");
        return scanner.nextLine();
    }

    public Transaction getPaymentDetails() {
        System.out.print("Enter payment details (mode, etc): ");
        String[] details = scanner.nextLine().split(" ");
        // Return a PaymentMethod based on input
        PaymentMethod paymentMethod = new UPI(details[2]);
        return new Transaction(details[1], paymentMethod, false);
    }

    public void showInvalidOption() {
        System.out.println("Invalid option. Please try again.");
    }
}

