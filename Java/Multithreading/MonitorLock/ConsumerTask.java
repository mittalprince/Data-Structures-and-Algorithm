public class ConsumerTask implements Runnable{
    SharedResource sharedResource;

    ConsumerTask(SharedResource resource) { this.sharedResource = resource; }

    public void run(){
        System.out.println("Consumer Thread: " + Thread.currentThread().getName());
        sharedResource.getItem()
    }
}