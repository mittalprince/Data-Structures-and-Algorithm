package ObserverDesignPattern.Observable;

import ObserverDesignPattern.Observer.NotificationAlertObserver;

public class IphoneObservable implements StoreObservable {
    public List<NotificationAlertObserver> observerList = new ArrayList<>();
    public int stockCount = 0;

    public void add(NotificationAlertObserver observer){
        observerList.add(observer);
    }
    public void remove(NotificationAlertObserver observer){
        observerList.remove(observer);
    }
    public void notifySubsribers(){
        for(NotificationAlertObserver observer: observerList){
            observer.update();
        }
    }
    public void setStockCount(int stockAdded){
        if(stockCount == 0){
            notifySubsribers();
        }
        stockCount += stockAdded;
    }

    public int getStockCount(){
        return this.stockCount;
    }
}