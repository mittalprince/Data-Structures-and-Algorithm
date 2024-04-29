package ObserverDesignPattern.Observable;

import ObserverDesignPattern.Observable.StoreObservable;

public class EmailAlertObserver implements NotificationAlertObserver {
    String emailId;
    StockObservable observable;

    public EmailAlertObserver(String emailId, StockObservable observable){
        this.emailId = emailId;
        this.observable = observable;
    }

    public void update(){
        sendMail(emailId, "product is in stock");
    }
    private void sendMail(String emailId, String msg){
        // send email
    }
}
