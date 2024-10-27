package com.example.communicationSystem;
import com.example.communicationSystem.Constants.Constant;
import com.example.communicationSystem.request.Request;
import com.example.communicationSystem.request.RequestFactory;

import java.util.*;
import java.io.*;

public class CommandParser {
    ProviderManager providerManager = ProviderManager.getInstance();

    public void processCommandFromFile(String filename) throws Exception {
        Scanner scanner = new Scanner(new File(filename));
        while (scanner.hasNextLine()){
            try {
                String command = scanner.nextLine();
                executeCommand(command);
                System.out.println(" ");
            } catch (Exception e) {
                System.out.println(e.getMessage());
//                throw new Exception(e.getMessage());
                continue;
            }
        }
        scanner.close();
    }

    private void executeCommand(String command) throws Exception{
        String[] token = command.split(" ");
        switch (token[0]){
            case Constant.ADD_PROVIDER:
                this.addProvider(token);
                break;
            case Constant.PROCESS_REQUEST:
                this.processRequest(token);
                break;
            case Constant.UPDATE_STATE:
                this.updateState(token);
                break;
            default:
                throw new Exception("Invalid Command");
        }
    }

    private void addProvider(String[] token) throws Exception{
        if(token.length < 8) throw new Exception("Provider IncompleteProvider arguments");
        String providerName = token[1];
        String accountName = token[2];
        String channelType = token[3];
        String endPoint = token[4];
        String username = token[5];
        String password = token[6];
        boolean isCritical = Boolean.parseBoolean(token[7]);
        System.out.println("Adding provider: " + providerName + " for account " + accountName + " channel " + channelType + " Critical " + isCritical);
        if(providerManager.checkProviderExist(providerName)){
            Provider provider = providerManager.getProvider(providerName);
            Account account = provider.getAccounts().get(0);
            account.addChannel(ChannelType.valueOf(channelType), endPoint);
            p
        } else {
            Map<ChannelType, String> endpoints = new HashMap<>();
            endpoints.put(ChannelType.valueOf(channelType), endPoint);
            Account account = new Account(accountName, endpoints, username, password, isCritical);
            Provider provider = new Provider(providerName, providerName, List.of(account), true);
            providerManager.addProvider(provider);
        }
    }
    private void processRequest(String[] token)  throws Exception{
        Request request = RequestFactory.getRequest(token);
        CommunicationService communicationService = new CommunicationService();
        communicationService.processRequest(request);
    }
    private void updateState(String[] token) throws Exception{
        String providerName = token[1];
        boolean status = Boolean.parseBoolean(token[2]);
        providerManager.updateState(providerName, status);
        String stat = status ? "Enabling" : "Disabling" ;
        System.out.println(stat + " " + providerName +"...");
    }
}
