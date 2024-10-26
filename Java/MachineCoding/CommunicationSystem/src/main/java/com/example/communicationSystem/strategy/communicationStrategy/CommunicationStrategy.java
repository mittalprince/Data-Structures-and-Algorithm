package com.example.communicationSystem.strategy.communicationStrategy;

import com.example.communicationSystem.Account;
import com.example.communicationSystem.request.Request;

public interface CommunicationStrategy {
    boolean sendRequest(Request request, Account account) throws Exception;
}
