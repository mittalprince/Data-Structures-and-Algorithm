package com.example.communicationSystem.strategy.requestValidator;

import com.example.communicationSystem.request.Request;
import com.example.communicationSystem.request.SmsRequest;

public class SmsRequestValidator implements RequestValidator{
    @Override
    public void validate(Request request) throws Exception {
        if (!(request instanceof SmsRequest)) throw new IllegalArgumentException("Invalid request type.");
        SmsRequest smsRequest = (SmsRequest) request;
        if (smsRequest.getPhoneNumber() == null || smsRequest.getMessage() == null) {
            throw new Exception("Missing fields in SMS request.");
        }
    }
}
