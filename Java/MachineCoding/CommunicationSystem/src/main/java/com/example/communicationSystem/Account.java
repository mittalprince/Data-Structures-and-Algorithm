package com.example.communicationSystem;
import java.util.Map;

public class Account {
    private final String accountId;
    private final Map<ChannelType, String> apiEndpoints; // Channel -> Endpoint URL
    private final String username;
    private final String password;
    private final boolean isCritical; // account for handling critical request

    public Account(String accountId, Map<ChannelType, String> apiEndpoints, String username, String password, boolean isCritical) {
        this.accountId = accountId;
        this.apiEndpoints = apiEndpoints;
        this.username = username;
        this.password = password;
        this.isCritical = isCritical;
    }

    public String getAccountId() {
        return accountId;
    }

    public String getApiEndpoint(ChannelType channelType) {
        return apiEndpoints.get(channelType);
    }

    public String getUsername() {
        return username;
    }

    public String getPassword() {
        return password;
    }

    public boolean isCritical() {
        return isCritical;
    }

    // Check if the account supports a specific channel type
    public boolean supportsChannel(ChannelType channelType) {
        return apiEndpoints.containsKey(channelType);
    }
}
