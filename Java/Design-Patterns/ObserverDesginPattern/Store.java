package ObserverDesignPattern;

import ObserverDesignPattern.Observable.IphoneObservable;
import ObserverDesignPattern.Observable.StoreObservable;
import ObserverDesignPattern.Observer.NotificationAlertObserver;
import ObserverDesignPattern.Observer.EmailAlertObserver;
import ObserverDesignPattern.Observer.MobileAlertObserver;

public class Store {
    public static void main(String agrs[]){
        StoreObservable iphoneObservable = new StoreObservable();
        NotificationAlertObserver observer1 = new EmailAlertObserver("xyz@gmail.com", iphoneObservable);
        NotificationAlertObserver observer2 = new EmailAlertObserver("abc@gmail.com", iphoneObservable);
        NotificationAlertObserver observer3 = new EmailAlertObserver("817882XXXX", iphoneObservable);

        iphoneObservable.add(observer1);
        iphoneObservable.add(observer2);
        iphoneObservable.add(observer3);

        iphoneObservable.setStockCount(10);
    }
}