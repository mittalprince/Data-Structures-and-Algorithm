public class Main {
    public static void main(String args[]){
        SharedResource resource = new SharedResource();
        Thread t1 = new Thread(() -> {
            resource.produce();
        });
        Thread t2 = new Thread(() -> {
            resource.consume();
        });
        t1.start();
        t2.start();
    }
}

/*
t1 start -> produce -> acquire optimistic read lock with stamp
do update operation and goes to sleep
meanwhile t2 start -> consume -> acquire write lock with stamp;
do update operation
unlock lock with stamp
t1 resume -> validate the stamp which is alredy changed by t2
invalidate -> rollback update done by t1;
 */

/*
taken optimistic read;
write lock acquired by thread 1
performing work
write lock released by thread 1
rollback of work
 */