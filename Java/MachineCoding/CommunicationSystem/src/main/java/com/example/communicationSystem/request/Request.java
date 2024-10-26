package com.example.communicationSystem.request;

import com.example.communicationSystem.Account;
import com.example.communicationSystem.ChannelType;
import com.example.communicationSystem.strategy.communicationStrategy.CommunicationStrategy;
import com.example.communicationSystem.strategy.requestValidator.RequestValidator;

public abstract class Request {
    private ChannelType channel;
    private String sender;
    private String message;
    private boolean isCrtical;
    private final RequestValidator validator;
    private final CommunicationStrategy communicationStrategy;

    public Request(RequestValidator validator, CommunicationStrategy communicationStrategy) {
        this.validator = validator;
        this.communicationStrategy = communicationStrategy;
    }
    public Request(ChannelType channel, String sender, String message, boolean isCritical, RequestValidator validator, CommunicationStrategy communicationStrategy) {
        this.channel = channel;
        this.message = message;
        this.sender = sender;
        this.isCrtical = isCritical;
        this.validator = validator;
        this.communicationStrategy = communicationStrategy;
    }
    public void validate() throws Exception{
        validator.validate(this);
    }
    public boolean sendRequest(Account account) throws Exception{
        return communicationStrategy.sendRequest(this, account);
    }
    public String getSender() { return sender; }
    public String getMessage() { return message; }
    public ChannelType getChannel() { return channel; }
    public boolean isCrtical() {return isCrtical;}
}
