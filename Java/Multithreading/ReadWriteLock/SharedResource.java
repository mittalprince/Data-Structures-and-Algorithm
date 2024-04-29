import java.util.concurrent.locks.ReadWriteLock;

public class SharedResource {
    bool isAvailable = false;
    public void produce(ReadWriteLock lock){
        try{
            lock.readLock().lock();
            System.out.println("Read lock acquired: ": Thread.currentThred().getName());
            Thread.sleep(4000);
        } catch (Exception e){

        } finally {
            lock.readLock().unlock();
            System.out.println("Read lock released: ": Thread.currentThred().getName());
        }
    }
    public void consume(ReadWriteLock lock){
        try{
            lock.writeLock().lock();
            System.out.println("Write lock acquired: ": Thread.currentThred().getName());
           isAvailable = true
        } catch (Exception e){

        } finally {
            lock.writeLock().unlock();
            System.out.println("Write lock released: ": Thread.currentThred().getName());
        }
    }
}