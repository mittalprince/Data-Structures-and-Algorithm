package com.example.communicationSystem.request;

import com.example.communicationSystem.ChannelType;
import com.example.communicationSystem.strategy.communicationStrategy.CommunicationStrategy;
import com.example.communicationSystem.strategy.requestValidator.RequestValidator;

public class EmailRequest extends Request{
    private final String receiver;
    private final String subject;

    public EmailRequest(String sender, String message, String receiver, String subject, boolean isCritical, CommunicationStrategy emailCommunicationStrategy, RequestValidator emailRequestValidator) {
        super(ChannelType.EMAIL, sender, message, isCritical, emailRequestValidator, emailCommunicationStrategy);
        this.receiver = receiver;
        this.subject = subject;
    }

    public String getReceiver() { return receiver; }
    public String getSubject() { return subject; }
}
