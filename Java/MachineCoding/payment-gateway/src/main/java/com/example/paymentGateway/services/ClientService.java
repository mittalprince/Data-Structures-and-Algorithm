package com.example.paymentGateway.services;
import com.example.paymentGateway.models.entities.Client;
import com.example.paymentGateway.models.entities.PaymentMode;

import java.util.HashMap;
import java.util.Map;
import java.util.List;
import java.util.Set;

public class ClientService {
    private Map<String, Client> clients = new HashMap<>();

    public void addClient(String clientName) {
        clients.put(clientName, new Client(clientName, Set.of(PaymentMode.UPI, PaymentMode.CARD)));
    }

    public Client getClient(String clientName) {
        return clients.get(clientName);
    }
    public void removeClient(String clientName){
        clients.remove(clientName);
    }
}
