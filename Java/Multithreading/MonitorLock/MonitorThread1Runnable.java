public class MonitorThread1Runnable implements Runnable{
    MonitorLockExample obj;
    MonitorThread1Runnable(MonitorLockExample obj){
        this.obj = obj;
    }
    public void run(){
        obj.task1();
    }
}