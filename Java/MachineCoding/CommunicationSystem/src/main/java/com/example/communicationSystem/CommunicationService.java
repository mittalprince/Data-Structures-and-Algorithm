package com.example.communicationSystem;
import com.example.communicationSystem.request.Request;

import java.util.*;

public class CommunicationService {
    private final ProviderManager providerManager;

    public CommunicationService(){
        this.providerManager = ProviderManager.getInstance();
    }

    public void processRequest(Request request) throws Exception{
        try {
            request.validate();
            Map<String, List<Account>> activeProvidersAccounts = providerManager.getProvidersForChannel(request.getChannel(), request.isCrtical());
            if (activeProvidersAccounts.isEmpty()) throw new Exception("No active providers for this channel");

            // Track used providers to avoid retrying the same provider multiple times
            Set<String> attemptedProviders = new HashSet<>();
            for(Map.Entry<String, List<Account>> entry: activeProvidersAccounts.entrySet()) {
                String providerId = entry.getKey();
                Account account = entry.getValue().get(new Random().nextInt(entry.getValue().size()));
                boolean success = sendRequestToProviderAccount(request, account, providerId);
                if(success) return;
            }
        } catch (Exception e){
            throw new Exception(e.getMessage());
        }
    }

    private boolean sendRequestToProviderAccount(Request request, Account account, String providerId) throws Exception{
        try {
            String endpoint = account.getApiEndpoint(request.getChannel());
            String username = account.getUsername();
            String password = account.getPassword();
            // Example of sending the request - in a real system, you would use an HTTP library here.
            System.out.printf("Sending %s request with providerId %s to %s with auth %s %s%n", request.getChannel(), providerId, endpoint, username, password);
            return request.sendRequest(account);
        } catch (Exception e) {
            throw new Exception(e.getMessage());
        }
    }
}
