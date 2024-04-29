public class Main {
    public static void main(String agrs[]){

        SharedResource sharedResource = new SharedResource();
        Thread producerThread = new Thread(new ProducerTask(sharedResource));
        Thread consumerThread = new Thread(new ConsumerTask(sharedResource));
        producerThread.start();
        consumerThread.start();
    }
}