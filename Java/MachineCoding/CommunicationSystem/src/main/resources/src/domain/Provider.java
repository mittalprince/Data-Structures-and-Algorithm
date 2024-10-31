package domain;

import request.Request;
import service.HTTPService;

import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class Provider {
    String name;
    String id;
    Map<ChannelType, String> supportedChannelTypeToAPIMapping;

    Map<Priority, Account> accounts;

    Status status;

    public Provider(String id, String name, Map<ChannelType, String> supportedChannelTypeToAPIMapping, Map<Priority, Account> accounts) {
        try {
            validateChannelTypeMapping(supportedChannelTypeToAPIMapping);
        } catch(IllegalArgumentException e) {
            System.err.println("Error creating Provider: " + e.getMessage());
            return;
        }
        this.id = id;
        this.name = name;
        this.accounts = accounts;
        this.supportedChannelTypeToAPIMapping = supportedChannelTypeToAPIMapping;
        this.status = Status.ACTIVE;
    }

    private void validateChannelTypeMapping(Map<ChannelType, String> supportedChannelTypeToAPIMapping) {
        if (supportedChannelTypeToAPIMapping==null || supportedChannelTypeToAPIMapping.isEmpty()) {
//            throw new IllegalArgumentException("Mapping cannot be null or empty");
        }
    }

    public String getName() {
        return name;
    }

    public String getId() {
        return id;
    }

    public Map<ChannelType, String> getSupportedChannelTypeToAPIMapping() {
        return supportedChannelTypeToAPIMapping;
    }

    public Map<Priority, Account> getAccounts() {
        return accounts;
    }
    public Status getStatus() {
        return status;
    }

    public void addAccount(Priority priority, Account account) {
        this.accounts.put(priority, account);
    }

    public void addChannelType(ChannelType channelType, String API) {
        this.supportedChannelTypeToAPIMapping.put(channelType, API);
    }

    public void setStatus(Status status) {
        this.status = status;
    }

    public boolean isActive() {
        return status.equals(Status.ACTIVE);
    }

    public void setSupportedChannelTypeToAPIMapping(Map<ChannelType, String> supportedChannelTypeToAPIMapping) {
        this.supportedChannelTypeToAPIMapping = supportedChannelTypeToAPIMapping;
    }

    public void setAccounts(Map<Priority, Account> accounts) {
        this.accounts = accounts;
    }

    public String makeAPICall(HTTPService httpService, String username, String password, String api, String message) {
        //construct HTTP call
        return "Processed request";
    }
}
