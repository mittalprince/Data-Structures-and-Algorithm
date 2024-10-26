package com.example.communicationSystem.strategy.communicationStrategy;

import com.example.communicationSystem.Account;
import com.example.communicationSystem.request.EmailRequest;
import com.example.communicationSystem.request.Request;

public class EmailCommunicationStrategy implements CommunicationStrategy {
    @Override
    public boolean sendRequest(Request request, Account account) throws Exception{
        try {
            EmailRequest emailRequest = (EmailRequest) request;
            // Code to send email using provider integration
            System.out.println("Email sent to " + emailRequest.getReceiver() + " with " + account.getAccountId());
            return true;
        } catch (Exception e) {
            throw new Exception(e.getMessage());
        }
    }
}
