package com.example.communicationSystem;

import java.util.ArrayList;
import java.util.Map;
import java.util.HashMap;
import java.util.List;

public class ProviderManager {
    private static ProviderManager instance;
    private Map<String, Provider> providers = new HashMap<>();

    private ProviderManager(){};

    public static ProviderManager getInstance(){
        if(instance == null){
            synchronized (ProviderManager.class){
                if(instance == null){
                    instance = new ProviderManager();
                }
            }
        }
        return instance;
    }

    public void addProvider(Provider provider) throws Exception{
        if (provider == null || providers.containsKey(provider.getId())) {
            throw new Exception("Provider validation failed or already exists");
        }
        provider.validateProvider();
        providers.put(provider.getId(), provider);
    }
    public Provider getProvider(String providerId) throws Exception{
        Provider provider = providers.get(providerId);
        if (provider == null) throw new Exception("Provider not found");
        return provider;
    }
    public void updateState(String providerId, boolean active) throws Exception {
        Provider provider = getProvider(providerId);
        provider.setActive(active);
    }

    public Map<String, List<Account>> getProvidersForChannel(ChannelType channel, boolean isCritical){
        Map<String, List<Account>> activeProvidersAccounts = new HashMap<>();
        for(Provider provider: providers.values()){
            if(provider.isActive()){
                List<Account> activeAccount = provider.getAccountForChannel(channel, isCritical);
                if(!activeAccount.isEmpty()) activeProvidersAccounts.put(provider.getId(), activeAccount);
            }
        }
        return activeProvidersAccounts;
    }
    public void updateProvider(Provider provider) throws Exception{
        String providerId = provider.getId();
        Provider existingProvider = getProvider(providerId);
        // update the provider attributes
        providers.put(providerId, provider);
    }
    public boolean checkProviderExist(String providerId){
        return providers.containsKey(providerId);
    }
}
