package ObserverDesignPattern.Observable;

import ObserverDesignPattern.Observable.StoreObservable;

public class MobileAlertObserver implements NotificationAlertObserver {
    String username;
    StockObservable observable;

    public EmailAlertObserver(String username, StockObservable observable){
        this.username = username;
        this.observable = observable;
    }

    public void update(){
        sendMsgOnMobile(username, "product is in stock");
    }
    private void sendMsgOnMobile(String username, String msg){
        // send messgae
    }
}
