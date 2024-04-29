public class SharedResource {
    boolean itemAvailable = false;

    //sync put the monitor lock
    public synchronized void addItem(){
        itemAvailable = true;
        System.out.println("Item Added by: " + Thread.currentThread().getName() + " and invoking");
        notifyAll(); // notify all thrad which are in wait state of same obj
    }
    public synchronized void consumeItem(){
        System.out.println("Consume Method invoked by: " + Thread.currentThread().getName() + " and invoking");
        while(!itemAvailable){
            try {
                System.out.println("Thread : " + Thread.currentThread().getName() + " is waiting");
                wait(); // release the monitor lock
            } catch (Exception e){

            }
        }
        System.out.println("Item Consumed by: " + Thread.currentThread().getName() + " and invoking");
        itemAvailable = false;
    }
}