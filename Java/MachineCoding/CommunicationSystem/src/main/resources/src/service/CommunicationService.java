package service;

import domain.*;
import request.Request;
import strategy.ProviderSelectionStrategyInterface;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.concurrent.ConcurrentHashMap;

public class CommunicationService {
    private static CommunicationService instance;
    private CommunicationService() {
    }
    public static synchronized CommunicationService getInstance(ProviderSelectionStrategyInterface strategy) {
        if (instance == null) {
            instance = new CommunicationService(strategy);
        }
        return instance;
    }
    Map<ChannelType, List<String>> channelTypeToProviderIDMapping;
    ProviderSelectionStrategyInterface strategy;

    Map<String, Provider> providers;

    HTTPService httpService;

    public CommunicationService(ProviderSelectionStrategyInterface strategy) {
        this.providers = new ConcurrentHashMap<>(); //map to handle concurrency
        this.strategy = strategy;
        this.channelTypeToProviderIDMapping = new HashMap<>();
        this.channelTypeToProviderIDMapping.put(ChannelType.SMS, new ArrayList<>());
        this.channelTypeToProviderIDMapping.put(ChannelType.EMAIL, new ArrayList<>());
        this.channelTypeToProviderIDMapping.put(ChannelType.SOUNDBOX, new ArrayList<>());
        httpService = HTTPService.getInstance();
    }


    public boolean addProvider(String name, Map<ChannelType, String> supportedChannelTypeToAPIMapping, Map<Priority, Account> accounts) {
        Provider provider = new Provider(name, name, supportedChannelTypeToAPIMapping, accounts);
        if (provider.getId().isEmpty()) {
            return false;
        }
        if (validateDuplicate(provider.getId())) {
            return false;
        }
        providers.put(provider.getId(), provider);
        for (ChannelType type : supportedChannelTypeToAPIMapping.keySet()) {
            this.channelTypeToProviderIDMapping.get(type).add(provider.getId());
        }

        return true;
    }

    private boolean validateDuplicate(String id) {
        for (Provider provider : providers.values()) {
            if (provider.getId().equals(id)) {
                return true;
            }
        }
        return false;
    }

    public void getProvider(String id) {
        Provider provider = providers.get(id);
        System.out.println("ProviderID: "+provider.getId() + " " + "Provider NAME: "+ provider.getName() + " " + "Provider STATUS: "+ provider.getStatus());
        System.out.print("Here are the channels and APIs: ");
        for (Map.Entry<ChannelType, String> entry : provider.getSupportedChannelTypeToAPIMapping().entrySet()) {
            System.out.print("Channel: "+entry.getKey() + " API: " + entry.getValue());
        }
        System.out.print("Here are the priorities and accounts: ");
        for (Map.Entry<Priority, Account> entry : provider.getAccounts().entrySet()) {
            System.out.println("Priority: "+entry.getKey() + " Account: " + entry.getValue().getUsername());
        }
    }

    public void updateStatus(String providerID, Status status) {
        Status st = this.providers.get(providerID).getStatus();
        this.providers.get(providerID).setStatus(status);
        System.out.println("Status for provider: "+providerID +" changed to: "+status + " from: "+st);
    }


    public void updateDetails(Provider provider) {
        //not changing name and id as they have been used interchangeably for the ease of reading and handling
        if (provider == null) {
            return;
        }
        if(providers.get(provider.getId())!=null) {
            Provider oldProvider = providers.get(provider.getId());
            if(provider.getSupportedChannelTypeToAPIMapping()!=null) {
                oldProvider.setSupportedChannelTypeToAPIMapping(provider.getSupportedChannelTypeToAPIMapping());
            }
            if(provider.getAccounts()!=null) {
                oldProvider.setAccounts(provider.getAccounts());
            }
        }

    }

    public String processRequest(Request request, Priority priority) {
        System.out.println("Processing request: "+request.message+" with priority: "+priority);
        List<String> potentialProviders = channelTypeToProviderIDMapping.get(request.channelType);
        List<Provider> providerslist = new ArrayList<>();
        for (int i = 0; i < potentialProviders.size(); i++) {
            Provider potential = providers.get(potentialProviders.get(i));
            if (potential.isActive()) {
                providerslist.add(potential);
            }

        }

        if(providerslist.isEmpty()) {
            System.out.println("No providers to process your request");
            return "erorrrr";
        }
        Provider eligibleProvider = strategy.selectProvider(providerslist);
        String API = eligibleProvider.getSupportedChannelTypeToAPIMapping().get(request.channelType);
        Account accountInfo;
        if(eligibleProvider.getAccounts().get(priority)==null) {
            accountInfo = eligibleProvider.getAccounts().get(Priority.LOW_PRIORITY);
        } else {
            accountInfo = eligibleProvider.getAccounts().get(priority);
        }
        //making call
        System.out.println("Making call to httpservice for request: "+ request.message+" by provider: "+eligibleProvider.getName()+ " and account: "+accountInfo.getUsername());
        String response = eligibleProvider.makeAPICall(httpService, accountInfo.getUsername(), accountInfo.getPassword(),API, request.message); //this can have HTTP code as well
        return response;
    }


}
