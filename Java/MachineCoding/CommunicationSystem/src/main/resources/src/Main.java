import domain.*;
import factory.RequestFactory;
import request.SMSRequest;
import service.CommunicationService;
import strategy.DefaultProviderSelectionStrategy;
import strategy.ProviderSelectionStrategyInterface;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class Main {
    static CommunicationService communicationService;
    public static void main(String[] args) {
        ProviderSelectionStrategyInterface strategy = new DefaultProviderSelectionStrategy();
        communicationService = CommunicationService.getInstance(strategy);


        Map<ChannelType, String> supportedChannelTypeToAPIMapping = new HashMap<>();
        supportedChannelTypeToAPIMapping.put(ChannelType.SMS, "API-1");

        Map<Priority, Account > accounts = new HashMap<>();
        List<ChannelType> channelTypeList = new ArrayList<>();
        channelTypeList.add(ChannelType.SMS);
        accounts.put(Priority.HIGH_PRIORITY, new Account("u1", "p1", channelTypeList));
        accounts.put(Priority.LOW_PRIORITY, new Account("u2", "p2", channelTypeList));
        communicationService.addProvider("P1", supportedChannelTypeToAPIMapping, accounts);
        communicationService.addProvider("P2", supportedChannelTypeToAPIMapping, accounts);
        communicationService.addProvider("P3", supportedChannelTypeToAPIMapping, accounts);

        communicationService.getProvider("P1");
        communicationService.getProvider("P2");
        communicationService.getProvider("P3");

        communicationService.updateStatus("P1", Status.ACTIVE);

        communicationService.updateDetails(new Provider("P1", "P1", null, null));


        RequestFactory requestFactory = new RequestFactory();
        SMSRequest request = (SMSRequest)requestFactory.getRequest(ChannelType.SMS);
        request.enterDetails("9873309250", "message");

       String response= communicationService.processRequest(request, Priority.HIGH_PRIORITY); //this can be a json body with httpcode


    }
}