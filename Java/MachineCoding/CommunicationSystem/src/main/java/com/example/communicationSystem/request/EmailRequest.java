package com.example.communicationSystem.request;

import com.example.communicationSystem.ChannelType;
import com.example.communicationSystem.Constants.Constant;
import com.example.communicationSystem.strategy.communicationStrategy.CommunicationStrategy;
import com.example.communicationSystem.strategy.communicationStrategy.EmailCommunicationStrategy;
import com.example.communicationSystem.strategy.requestValidator.EmailRequestValidator;
import com.example.communicationSystem.strategy.requestValidator.RequestValidator;

public class EmailRequest extends Request{
    private String receiver;
    private String subject;

    public EmailRequest() {
        super(new EmailRequestValidator(), new EmailCommunicationStrategy());
    }
    public EmailRequest(String sender, String message, String receiver, String subject, boolean isCritical, CommunicationStrategy emailCommunicationStrategy, RequestValidator emailRequestValidator) {
        super(ChannelType.EMAIL, sender, message, isCritical, emailRequestValidator, emailCommunicationStrategy);
        this.receiver = receiver;
        this.subject = subject;
    }

    public String getReceiver() { return receiver; }
    public void setReceiver(String receiver) { this.receiver = receiver; }
    public String getSubject() { return subject; }
    public void setSubject(String subject) { this.subject = subject; }
}
