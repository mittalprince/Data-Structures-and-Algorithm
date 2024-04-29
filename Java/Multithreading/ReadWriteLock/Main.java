public class Main {
    public static void main(String args[]){
        SharedResource resource = new SharedResource();
        ReadWriteLock lock = new ReentrantReadWriteLock();

        Thread t1 = new Thread(() -> {
            resource.produce(lock); // acquire read lock
        });
        Thread t3 = new Thread(() -> {
            resource.produce(lock); // acquire read lock
        });
        Thread t3 = new Thread(() -> {
            resource.consume(lock); // acquire write lock
        });

        t1.start();
        t2.start();
        t3.start();
    }
}
// Lock acquired by thread 0
// Lock acquired by thread 1
// wait till 4 sec
// Lock released by thread 0
// Lock released by thread 1
// Lock acquired by thread 2
// Lock released by thread 2