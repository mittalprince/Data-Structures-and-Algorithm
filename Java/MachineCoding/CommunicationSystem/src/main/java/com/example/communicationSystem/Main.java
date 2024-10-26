package com.example.communicationSystem;
import com.example.communicationSystem.factory.CommunicationStrategyFactory;
import com.example.communicationSystem.factory.RequestValidatorFactory;
import com.example.communicationSystem.request.EmailRequest;

import java.util.List;
import java.util.Map;

public class Main {
    public static void main(String[] args) {
        ProviderManager providerManager = ProviderManager.getInstance();

        Map<ChannelType, String> endpoints = Map.of(ChannelType.EMAIL, "https://email-api.com/send", ChannelType.SMS, "https://sms-api.com/send");
        String username = "user";
        String password = "pass";
        Account account = new Account("acc124", endpoints, username, password, false);
        Provider emailProvider = new Provider("1", "EmailProvider", List.of(account), true);
        try {
            providerManager.addProvider(emailProvider);
            EmailRequest emailRequest = new EmailRequest("sender@example.com", "Message", "receiver@example.com", "Subject", false, CommunicationStrategyFactory.getCommunicationStrategy(ChannelType.EMAIL), RequestValidatorFactory.getRequestValidator(ChannelType.EMAIL));
            CommunicationService communicationService = new CommunicationService();
            communicationService.processRequest(emailRequest);
        } catch (Exception e){
            System.out.println(e.getMessage());
        }
    }
}
