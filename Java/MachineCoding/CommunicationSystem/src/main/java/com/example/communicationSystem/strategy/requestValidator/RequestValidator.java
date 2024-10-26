package com.example.communicationSystem.strategy.requestValidator;
import com.example.communicationSystem.request.Request;

public interface RequestValidator {
    void validate(Request request) throws Exception;
}
