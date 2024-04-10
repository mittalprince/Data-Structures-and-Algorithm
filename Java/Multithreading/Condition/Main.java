public class Main {
    public static void main(String args[]){
        SharedResource resource = new SharedResource();
        Thread t1 = new Thread(() -> {
            for(int i=0; i<2; i++){
                resource.produce();
            }
        });
        Thread t2 = new Thread(() -> {
            for(int i=0; i<2; i++){
                resource.consume();
            }
        });
        t1.start();
        t2.start();
    }
}
/*
Produce lock acquired by thread 0
Produce lock released by thread 0
Produce lock acquired by thread 0
Produce thread is waiting thread 0
Consumer lock acquired by thread 1
Consumer lock released by thread 1
Produce lock released by thread 0
Consumer lock acquired by thread 1
Consumer lock released by thread 1
 */