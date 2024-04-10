public class SharedResource {
    boolean isAvailable = true;

    public void produce(ReentrantLock lock){
        try{
            lock.lock();
            System.out.println("Lock acquired by: "+ Thread.currentThread().getName());
            isAvailable = true;
            Thread.sleep(4000);
        } catch (Exception e){

        }
        finally {
            lock.unlock();
            System.out.println("Lock released by: "+ Thread.currentThread().getName());
        }
    }
}