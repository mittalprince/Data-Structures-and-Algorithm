public class SharedResource {
   boolean isAvailable = false;
   Semaphore lock = new Semaphore(2); // permit=2, how many thready can take lock same time;
    public void producer(){
        try{
            lock.acquire();
            System.out.println("Read lock acquired: ": Thread.currentThred().getName());
            isAvailable = true;
            Thread.sleep(4000);
        } catch (Exception e){

        } finally {
            lock.release();
            System.out.println("Read lock released: ": Thread.currentThred().getName());
        }
    }
}