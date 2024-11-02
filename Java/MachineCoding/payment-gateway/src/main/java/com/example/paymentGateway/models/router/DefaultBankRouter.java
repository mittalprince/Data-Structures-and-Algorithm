package com.example.paymentGateway.models.router;

import com.example.paymentGateway.models.entities.Bank;
import com.example.paymentGateway.models.entities.PaymentMode;
import com.example.paymentGateway.models.entities.Transaction;

import java.util.List;

public class DefaultBankRouter implements BankRouterStrategy{
    @Override
    public Bank routeTransaction(Transaction transaction, List<Bank> banks) throws Exception{
        Bank resp =  null;
        for(Bank bank: banks){
            if(resp == null) resp = bank;
         }
        if(resp == null) throw new IllegalArgumentException("No Bank exist for current payment mode");
        return resp;
    }
}
//public class BankRouter {
//    private List<Bank> banks;
//    private final Random random = new Random();
//
//    public BankRouter(List<Bank> banks){
//        this.banks = banks;
//    }
//    public Bank routeTransaction(PaymentMode paymentMode){
//        Bank resp = null;
//        for(Bank bank: banks){
//            double cumulativeWeight = 0;
//            double randomValue = random.nextDouble();
//            if(bank.supportPaymentMode(paymentMode)){
//                if(resp == null) resp = bank;
//                cumulativeWeight += bank.getAllocationForPaymentMode(paymentMode);
//                if (randomValue <= cumulativeWeight) {
//                    return bank;
//                }
//            }
//        }
//        if(resp == null){
//            throw new IllegalStateException("No bank available for this mode");
//        }
//        return resp;
//    }
//
//    public void addBank(Bank bank){
//        this.banks.add(bank);
//    }
//    public void removeBank(Bank bank){
//        this.banks.remove(bank);
//    }
//
//}
