import java.util.concurrent;

public class Main {
    public static void main(String args[]){
        ThreadPoolExecutor executor = new ThreadPoolExecutor(2, 4, 1, TimeUnit.MINUTES, new ArrayBlockingQueue<>(2), new CustomThreadFactory(), new CustomRejectHandler());
//        executor.allowCoreThreadTimeout(true);
        for(int i=1; i<=4; i++){
            executor.submit(() -> {
                try{
                    Thread.sleep(5000);
                } catch (Exception e){

                }
                System.out.println("Task processed by: " + Thread.currentThread().getName());
            })
        }
        executor.shutdown();
    }
}

class CustomThreadFactory implements ThreadFactory{
    @Override
    public Thread newThread(Runnable r){
        Thread th = new Thread(r);
        th.setPriority(Thread.NORM_PRIORITY);
        th.setDaemon(false);
        return th;
    }
}

class CustomRejectHandler implements RejectedExecutionHandler{
    @Override
    public void rejectedExecution(Runnable r, ThreadPoolExecutor executor){
        System.out.println("Task Rejected: " + r.toString());
    }
}

/*
task processed by: Thread-1 // first and second assign at once as we have two thread available
task processed by: Thread-0
task processed by: Thread-1
task processed by: Thread-0
 */