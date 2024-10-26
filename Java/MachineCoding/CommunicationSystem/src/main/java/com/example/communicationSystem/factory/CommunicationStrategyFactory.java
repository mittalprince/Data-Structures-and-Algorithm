package com.example.communicationSystem.factory;

import com.example.communicationSystem.strategy.communicationStrategy.CommunicationStrategy;
import com.example.communicationSystem.strategy.communicationStrategy.EmailCommunicationStrategy;
import com.example.communicationSystem.strategy.communicationStrategy.SmsCommunicationStrategy;
import com.example.communicationSystem.ChannelType;

public class CommunicationStrategyFactory {
    public static CommunicationStrategy getCommunicationStrategy(ChannelType requestType){
        switch (requestType){
            case EMAIL:
                return new EmailCommunicationStrategy();
            case SMS:
                return new SmsCommunicationStrategy();
            default:
                throw new IllegalArgumentException("Unknown request type: " + requestType);
        }
    }
}
