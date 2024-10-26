package com.example.communicationSystem.strategy.requestValidator;

import com.example.communicationSystem.request.EmailRequest;
import com.example.communicationSystem.request.Request;

public class EmailRequestValidator implements RequestValidator{
    @Override
    public void validate(Request request) throws Exception{
        if(!(request instanceof EmailRequest)) throw new IllegalArgumentException("Invalid request type.");
        EmailRequest emailRequest = (EmailRequest) request;
        if (emailRequest.getSender() == null || emailRequest.getReceiver() == null ||
                emailRequest.getSubject() == null || emailRequest.getMessage() == null) {
            throw new Exception("Missing fields in Email request.");
        }
    }
}
