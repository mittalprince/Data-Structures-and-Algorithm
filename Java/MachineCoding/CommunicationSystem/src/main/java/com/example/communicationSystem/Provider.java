package com.example.communicationSystem;

import java.util.ArrayList;
import java.util.Map;
import java.util.List;
import java.util.Optional;

public class Provider {
    private final String id;
    private String name;
    private List<Account> accounts;
    private boolean isActive;


    public Provider(String id, String name, List<Account> accounts, boolean isActive) {
        this.id = id;
        this.name = name;
        this.accounts = accounts;
        this.isActive = isActive;
    }

    public String getId() {return id;}
    public String getName() {return name;}
    public List<Account> getAccounts() {return accounts;}
    public void setAccounts(List<Account> accounts) {this.accounts = accounts;}
    public boolean isActive() {return isActive;}
    public void setActive(boolean active) {isActive = active;}
    public List<Account> getAccountForChannel(ChannelType channelType, boolean isCritical){
        List<Account> activeAccounts = new ArrayList<>();
        for(Account account: accounts){
            if((isCritical || !account.isCritical()) && account.supportsChannel(channelType)){
                activeAccounts.add(account);
            }
        }
        return activeAccounts;
    }
    public void validateProvider() throws Exception{
        if(this.getId() == null || this.getName() == null || this.getAccounts() == null){
            throw new Exception("Illegal Arguments, invalid provider");
        }
    }

    public boolean checkAccountExist(String accountId){
        return accounts.stream().anyMatch(account -> account.getAccountId().equalsIgnoreCase(accountId));
    }
}
