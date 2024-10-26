package com.example.communicationSystem.request;

import com.example.communicationSystem.ChannelType;
import com.example.communicationSystem.Constants.Constant;
import com.example.communicationSystem.strategy.communicationStrategy.SmsCommunicationStrategy;
import com.example.communicationSystem.strategy.requestValidator.SmsRequestValidator;

public class SmsRequest extends Request{
    private String phoneNumber;

    public SmsRequest(){
        super(new SmsRequestValidator(), new SmsCommunicationStrategy());
    }
    public SmsRequest(String sender, String message, String phoneNumber, boolean isCritical){
        super(ChannelType.SMS, sender, message, isCritical, new SmsRequestValidator(), new SmsCommunicationStrategy());
        this.phoneNumber = phoneNumber;
    }

    public String getPhoneNumber() { return phoneNumber; }
    public void setPhoneNumber(String phoneNumber) { this.phoneNumber = phoneNumber; }
}
