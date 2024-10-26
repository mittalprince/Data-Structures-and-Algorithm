package com.example.communicationSystem.request;

import com.example.communicationSystem.ChannelType;
import com.example.communicationSystem.strategy.communicationStrategy.CommunicationStrategy;
import com.example.communicationSystem.strategy.requestValidator.RequestValidator;

public class SmsRequest extends Request{
    private final String phoneNumber;
    public SmsRequest(String sender, String message, String phoneNumber, boolean isCritical, CommunicationStrategy communicationStrategy, RequestValidator requestValidator){
        super(ChannelType.SMS, sender, message, isCritical, requestValidator, communicationStrategy);
        this.phoneNumber = phoneNumber;
    }

    public String getPhoneNumber() { return phoneNumber; }
}
