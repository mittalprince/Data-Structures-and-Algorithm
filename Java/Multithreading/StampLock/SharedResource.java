public class SharedResource {
    int a = 10;
    StampLock lock = new StampLock();
    public void producer(){
        long stamp = lock.tryOptimisticRead();
        try{
            System.out.println("Taken optimistic lock");
            a = 11;
            Thread.sleep(6000);
            if(lock.isValidate(stamp)){
                System.out.println("updated value successfully");
            } else {
                System.out.println("rollback of work");
                a = 10;
            }
        } catch (Exception e){

        }
    }
    public void consume(){
        long stamp = lock.writeLock();
        System.out.println("Lock acquired by: " Thread.currentThread().getName());
        try{
            System.out.println("performing work");
            a = 9;
        }
        finally {
            lock.unlockWrite(stamp);
            System.out.println("Lock released by: " Thread.currentThread().getName());
        }
    }
}