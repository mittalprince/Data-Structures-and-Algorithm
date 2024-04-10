public class Main {
    public static void main(){
        ReentrantLock lock = new ReentrantLock();
        SharedResource resurce1 = new SharedResource();
        Thread t1 = new Thread(() -> {
            resource1.produce(lock);
        });

        SharedResource resurce2 = new SharedResource();
        Thread t2 = new Thread(() -> {
            resource2.produce(lock);
        });

        t1.start();
        t2.start();
    }
}