package com.example.communicationSystem.request;

import com.example.communicationSystem.ChannelType;
import com.example.communicationSystem.factory.CommunicationStrategyFactory;
import com.example.communicationSystem.factory.RequestValidatorFactory;

public class RequestFactory {
    public static Request getRequest(String[] token) throws Exception{
        String channelType = token[1];
        String sender, receiver, message, subject;
        boolean isCritical;
        switch (ChannelType.valueOf(channelType)){
            case EMAIL:
                if(token.length<7) throw new Exception("Incomplete arguments");
                sender = token[2];
                receiver = token[3];
                subject = token[4];
                message = token[5];
                isCritical = Boolean.parseBoolean(token[6]);
                System.out.println("Processing " + channelType + " request (Critical): " + isCritical);
                return new EmailRequest(sender, message, receiver, subject, isCritical, CommunicationStrategyFactory.getCommunicationStrategy(ChannelType.EMAIL), RequestValidatorFactory.getRequestValidator(ChannelType.EMAIL));
            case SMS:
                if(token.length < 5) throw new Exception("Incomplete arguments");
                receiver = token[2];
                message = token[3];
                isCritical = Boolean.parseBoolean(token[4]);
                return new SmsRequest("", message, receiver, isCritical, CommunicationStrategyFactory.getCommunicationStrategy(ChannelType.SMS), RequestValidatorFactory.getRequestValidator(ChannelType.SMS));
            default:
                throw new IllegalArgumentException("Unknown request type: " + channelType);
        }
    }
}
