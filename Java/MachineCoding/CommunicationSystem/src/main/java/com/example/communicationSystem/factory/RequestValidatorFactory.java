package com.example.communicationSystem.factory;

import com.example.communicationSystem.ChannelType;
import com.example.communicationSystem.strategy.requestValidator.EmailRequestValidator;
import com.example.communicationSystem.strategy.requestValidator.RequestValidator;
import com.example.communicationSystem.Constants.Constant;
import com.example.communicationSystem.strategy.requestValidator.SmsRequestValidator;

public class RequestValidatorFactory {
    public static RequestValidator getRequestValidator(ChannelType requestType){
        switch (requestType){
            case EMAIL:
                return new EmailRequestValidator();
            case SMS:
                return new SmsRequestValidator();
            default:
                throw new IllegalArgumentException("Unknown request type: " + requestType);
        }
    }
}
