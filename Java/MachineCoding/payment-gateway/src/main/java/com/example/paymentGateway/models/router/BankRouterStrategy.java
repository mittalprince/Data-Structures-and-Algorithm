package com.example.paymentGateway.models.router;

import com.example.paymentGateway.models.entities.Bank;
import com.example.paymentGateway.models.entities.Transaction;

import java.util.List;

public interface BankRouterStrategy {
    Bank routeTransaction(Transaction transaction, List<Bank> banks) throws Exception;
}