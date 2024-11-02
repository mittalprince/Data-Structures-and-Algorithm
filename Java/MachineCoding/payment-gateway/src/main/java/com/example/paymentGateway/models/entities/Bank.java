package com.example.paymentGateway.models.entities;

import java.util.List;
import java.util.Map;

public class Bank {
    private final String name;
    private Map<PaymentMode, Double> trafficAllocation;
    private Map<PaymentMode, String> apiEndpoint;

    public Bank(String name, Map<PaymentMode, Double> trafficAllocation, Map<PaymentMode, String> apiEndpoint) {
        this.name = name;
        this.trafficAllocation = trafficAllocation;
        this.apiEndpoint = apiEndpoint;
    }
    public String getName() {
        return name;
    }
    public Map<PaymentMode, Double> getTrafficAllocation() {
        return trafficAllocation;
    }
    public boolean processTransaction(PaymentMode paymentMode) {
        String endPoint = apiEndpoint.get(paymentMode);
        // call endpoint && Simulate transaction success/failure
        return Math.random() > 0.3;
    }
    public boolean supportPaymentMode(PaymentMode paymentMode){
        return apiEndpoint.containsKey(paymentMode);
    }
    public Double getAllocationForPaymentMode(PaymentMode paymentMode){
        return trafficAllocation.get(paymentMode);
    }
    public void addPaymentMode(PaymentMode paymentMode, Double allocation, String endPoint) throws Exception{
        if(trafficAllocation.containsKey(paymentMode)) throw new Exception("Payment mode already exist");
        trafficAllocation.put(paymentMode, allocation);
        apiEndpoint.put(paymentMode, endPoint);
    }
    public void removePaymentMode(PaymentMode paymentMode){
        if(!trafficAllocation.containsKey(paymentMode)) throw new IllegalArgumentException("Payment mode does not exist");
        trafficAllocation.remove(paymentMode);
        apiEndpoint.remove(paymentMode);
    }
    public List<PaymentMode> allSupportedPaymentMode(){
        return (List<PaymentMode>) trafficAllocation.keySet();
    }
}
