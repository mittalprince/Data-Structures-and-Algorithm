public class SharedResource {
    boolean itemAvailable = false;
    ReentrantLock lock = new ReentrantLock();
    Condition condition = new Condition();

    public void producer(){
        try{
            lock.lock();
            System.out.println("Produce Lock acquired by: "+ Thread.currentThread().getName());
            if(isAvailable){
                // already availablethread has to wait for it consume
                System.out.println("Produce thread is waiting: "+ Thread.currentThread().getName());
                condition.await();
            }
            isAvailable = true;
            condition.signal();
        } catch (Exception e){

        }
        finally {
            lock.unlock();
            System.out.println("Produce Lock released by: "+ Thread.currentThread().getName());
        }
    }

    public void consume(){
        try{
            Thread.sleep(4000);
            lock.lock();
            System.out.println("Consume Lock acquired by: "+ Thread.currentThread().getName());

            if(!isAvailable){
                // already not available, thread has to wait for it to produce
                System.out.println("Consume thread is waiting: "+ Thread.currentThread().getName());
                condition.await();
            }
            isAvailable = false;
            condition.signal();
        }
        catch (Exception e){

        }
        finally {
            lock.unlock();
            System.out.println("Consume Lock released by: "+ Thread.currentThread().getName());
        }
    }
}