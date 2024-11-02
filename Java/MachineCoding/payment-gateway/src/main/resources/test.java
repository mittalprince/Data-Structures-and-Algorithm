PaymentGatewayMVC
├── Controller
│   └── PaymentController.java            # Main controller orchestrating the process with service layer
├── Model
│   ├── entities
│   │   ├── Client.java                    # Client entity
│   │   ├── Bank.java                      # Bank entity
│   │   ├── PaymentMethod.java             # PaymentMethod abstract class and subclasses
│   ├── factory
│   │   └── PaymentProcessorFactory.java   # Factory for creating payment processors
│   ├── processor
│   │   └── PaymentProcessor.java          # PaymentProcessor strategy interface and implementations
│   └── router
│       └── BankRouter.java                # BankRouter for routing transactions based on rules
├── Service
│   ├── ClientService.java                 # Handles client-related business logic
│   ├── PaymentService.java                # Orchestrates the payment processing workflow
├── View
│   └── ConsoleView.java                   # Handles display logic
└── Main.java                              # Main entry point
Code Implementation
Main.java
        java
Copy code
public class Main {
    public static void main(String[] args) {
        PaymentController paymentController = new PaymentController();
        paymentController.initializeSystem();
        paymentController.run();
    }
}
Controller/PaymentController.java
        java
Copy code
import Service.ClientService;
import Service.PaymentService;
import View.ConsoleView;

public class PaymentController {
    private final ClientService clientService;
    private final PaymentService paymentService;
    private final ConsoleView consoleView;

    public PaymentController() {
        this.clientService = new ClientService();
        this.paymentService = new PaymentService();
        this.consoleView = new ConsoleView();
    }

    public void initializeSystem() {
        // Initialize system with default clients, banks, payment methods, etc.
        clientService.addClient("Flipkart");
        paymentService.initializeBanks();
    }

    public void run() {
        // Run the controller loop (pseudo code here)
        consoleView.showWelcomeMessage();
        while (true) {
            // Handle user inputs and perform actions
            consoleView.showOptions();
            String option = consoleView.getUserInput();
            switch (option) {
                case "1":
                    clientService.addClient(consoleView.getClientName());
                    break;
                case "2":
                    paymentService.processPayment(consoleView.getPaymentDetails());
                    break;
                default:
                    consoleView.showInvalidOption();
            }
        }
    }
}
Model/entities/Client.java
        java
Copy code
import java.util.List;

public class Client {
    private String name;
    private List<String> supportedPaymentModes;

    public Client(String name, List<String> supportedPaymentModes) {
        this.name = name;
        this.supportedPaymentModes = supportedPaymentModes;
    }

    public String getName() {
        return name;
    }

    public List<String> getSupportedPaymentModes() {
        return supportedPaymentModes;
    }
}
Model/entities/Bank.java
        java
Copy code
import java.util.Map;

public class Bank {
    private String name;
    private Map<String, Double> paymentDistribution;

    public Bank(String name, Map<String, Double> paymentDistribution) {
        this.name = name;
        this.paymentDistribution = paymentDistribution;
    }

    public String getName() {
        return name;
    }

    public boolean processTransaction(PaymentMethod paymentMethod) {
        return Math.random() > 0.5; // Random success/failure simulation
    }
}
Model/entities/PaymentMethod.java
        java
Copy code
public abstract class PaymentMethod {
    protected String mode;

    public PaymentMethod(String mode) {
        this.mode = mode;
    }

    public String getMode() {
        return mode;
    }
}

class UPI extends PaymentMethod {
    private String vpa;

    public UPI(String vpa) {
        super("UPI");
        this.vpa = vpa;
    }

    public String getVpa() {
        return vpa;
    }
}

class Card extends PaymentMethod {
    private String cardNumber;
    private String expiry;
    private String cvv;

    public Card(String cardNumber, String expiry, String cvv) {
        super("CARD");
        this.cardNumber = cardNumber;
        this.expiry = expiry;
        this.cvv = cvv;
    }
}
Model/factory/PaymentProcessorFactory.java
        java
Copy code
import Model.processor.PaymentProcessor;

public class PaymentProcessorFactory {
    public static PaymentProcessor getProcessor(String mode) {
        switch (mode) {
            case "UPI":
                return new UPIProcessor();
            case "CARD":
                return new CardProcessor();
            default:
                throw new IllegalArgumentException("Unsupported payment mode");
        }
    }
}
Model/processor/PaymentProcessor.java
        java
Copy code
import Model.entities.PaymentMethod;

public interface PaymentProcessor {
    boolean validate(PaymentMethod paymentMethod);
    boolean processTransaction(PaymentMethod paymentMethod);
}

class UPIProcessor implements PaymentProcessor {
    @Override
    public boolean validate(PaymentMethod paymentMethod) {
        // UPI specific validation
        return paymentMethod instanceof UPI && ((UPI) paymentMethod).getVpa() != null;
    }

    @Override
    public boolean processTransaction(PaymentMethod paymentMethod) {
        return true;
    }
}

class CardProcessor implements PaymentProcessor {
    @Override
    public boolean validate(PaymentMethod paymentMethod) {
        // Card specific validation
        return paymentMethod instanceof Card && ((Card) paymentMethod).getCvv() != null;
    }

    @Override
    public boolean processTransaction(PaymentMethod paymentMethod) {
        return true;
    }
}
Model/router/BankRouter.java
        java
Copy code
import Model.entities.Bank;
import Model.entities.PaymentMethod;

import java.util.List;

public class BankRouter {
    private List<Bank> banks;

    public BankRouter(List<Bank> banks) {
        this.banks = banks;
    }

    public Bank routeTransaction(PaymentMethod paymentMethod) {
        for (Bank bank : banks) {
            if (bank.processTransaction(paymentMethod)) {
                return bank;
            }
        }
        return null;
    }
}
Service/ClientService.java
        java
Copy code
import Model.entities.Client;

import java.util.HashMap;
import java.util.Map;

public class ClientService {
    private Map<String, Client> clients = new HashMap<>();

    public void addClient(String clientName) {
        clients.put(clientName, new Client(clientName, List.of("UPI", "CARD")));
    }

    public Client getClient(String clientName) {
        return clients.get(clientName);
    }
}
Service/PaymentService.java
        java
Copy code
import Model.entities.Bank;
import Model.entities.PaymentMethod;
import Model.factory.PaymentProcessorFactory;
import Model.router.BankRouter;

import java.util.List;

public class PaymentService {
    private List<Bank> banks;
    private BankRouter bankRouter;

    public PaymentService() {
        initializeBanks();
    }

    public void initializeBanks() {
        // Initialize banks and router here
        this.bankRouter = new BankRouter(banks);
    }

    public void processPayment(PaymentMethod paymentMethod) {
        var processor = PaymentProcessorFactory.getProcessor(paymentMethod.getMode());
        if (processor.validate(paymentMethod)) {
            Bank bank = bankRouter.routeTransaction(paymentMethod);
            bank.processTransaction(paymentMethod);
        }
    }
}
View/ConsoleView.java
        java
Copy code
import java.util.Scanner;

public class ConsoleView {
    private final Scanner scanner = new Scanner(System.in);

    public void showWelcomeMessage() {
        System.out.println("Welcome to the Payment Gateway!");
    }

    public void showOptions() {
        System.out.println("Select an option:");
        System.out.println("1: Add Client");
        System.out.println("2: Process Payment");
    }

    public String getUserInput() {
        return scanner.nextLine();
    }

    public String getClientName() {
        System.out.print("Enter client name: ");
        return scanner.nextLine();
    }

    public PaymentMethod getPaymentDetails() {
        System.out.print("Enter payment details (mode, etc): ");
        String[] details = scanner.nextLine().split(" ");
        // Return a PaymentMethod based on input
        return new UPI(details[1]); // Example; adjust as needed
    }

    public void showInvalidOption() {
        System.out.println("Invalid option. Please try again.");
    }
}
