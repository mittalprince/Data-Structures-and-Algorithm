package com.example.communicationSystem.strategy.communicationStrategy;

import com.example.communicationSystem.Account;
import com.example.communicationSystem.request.Request;
import com.example.communicationSystem.request.SmsRequest;

public class SmsCommunicationStrategy implements CommunicationStrategy {
    @Override
    public boolean sendRequest(Request request, Account account) throws Exception{
        try {
            SmsRequest smsRequest = (SmsRequest) request;
            // Code to send SMS using provider integration
            System.out.println("SMS sent to " + smsRequest.getPhoneNumber() + " with account " + account.getAccountId());
            return true;
        } catch (Exception e) {
            throw new Exception(e.getMessage());
        }
    }
}