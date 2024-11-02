package com.example.paymentGateway.services;

import com.example.paymentGateway.models.entities.Bank;
import com.example.paymentGateway.models.entities.PaymentMethod;
import com.example.paymentGateway.models.entities.PaymentMode;
import com.example.paymentGateway.models.entities.Transaction;
import com.example.paymentGateway.models.factory.PaymentProcessorFactory;
import com.example.paymentGateway.models.processor.PaymentProcessor;
import com.example.paymentGateway.models.router.BankRouterStrategy;
import com.example.paymentGateway.models.router.DefaultBankRouter;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class PaymentService {
    private Map<PaymentMode, List<Bank>> banks;
    private BankRouterStrategy bankRouter;

    public PaymentService(BankRouterStrategy bankRouterStrategy) {
        this.banks = new HashMap<>();
        bankRouter = bankRouterStrategy;
    }

    public void initializeBanks(){
        // initialize bank
    }
    public void processPayment(Transaction transaction) throws Exception{
        PaymentMode paymentMode = transaction.getPaymentMethod().getMode();
        if(!banks.containsKey(paymentMode)) throw new IllegalArgumentException("No Bank exist for current payment mode");
        PaymentProcessor processor = PaymentProcessorFactory.getProcessor(paymentMode);
        if(processor.validate(transaction.getPaymentMethod())){
            if(processor.processTransaction(transaction.getPaymentMethod())){
                Bank bank = bankRouter.routeTransaction(transaction, banks.get(paymentMode));
                bank.processTransaction(paymentMode);
            } else{
                System.out.println("Credentials are not valid");
            }
        } else {
            System.out.println("Invalid transaction");
        }
    }

    public void addBank(Bank bank){
        updatePaymentModeToBankMapping(bank);
    }
    public void removeBank(Bank bank){
        updatePaymentModeToBankMapping(bank);
    }
    public void updateBank(Bank bank){
        updatePaymentModeToBankMapping(bank);
    }
    private void updatePaymentModeToBankMapping(Bank bank){
        List<PaymentMode> paymentModes = bank.allSupportedPaymentMode();
        for(PaymentMode paymentMode: paymentModes){
            if(banks.containsKey(paymentMode)){
                List<Bank> b = banks.get(paymentMode);
                if(!b.contains(bank)) b.add(bank);
            } else {
                List<Bank> t = new ArrayList<>();
                t.add(bank);
                banks.put(paymentMode, t);
            }
        }
    }
}
