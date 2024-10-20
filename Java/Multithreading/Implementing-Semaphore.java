// Learn how to design and implement a simple semaphore class in Java.
// Your task is to implement a semaphore which takes in its constructor the maximum number of permits allowed and is also initialized with the same number of permits.

class Demonstration {
    public static void main( String args[] ) throws InterruptedException {

        final CountingSemaphore cs = new CountingSemaphore(1);

        Thread t1 = new Thread(new Runnable() {

            @Override
            public void run() {
                try {
                    for (int i = 0; i < 5; i++) {
                        cs.acquire();
                        System.out.println("Ping " + i);
                    }
                } catch (InterruptedException ie) {

                }
            }
        });

        Thread t2 = new Thread(new Runnable() {

            @Override
            public void run() {
                for (int i = 0; i < 5; i++) {
                    try {
                        cs.release();
                        System.out.println("Pong " + i);
                    } catch (InterruptedException ie) {

                    }
                }
            }
        });

        t2.start();
        t1.start();
        t1.join();
        t2.join();
    }
}

class CountingSemaphore {

    int usedPermits = 0;
    int maxCount;

    public CountingSemaphore(int count) {
        this.maxCount = count;

    }

    public synchronized void acquire() throws InterruptedException {

        while (usedPermits == maxCount)
            wait();

        notify();
        usedPermits++;

    }

    public synchronized void release() throws InterruptedException {

        while (usedPermits == 0)
            wait();

        usedPermits--;
        notify();
    }
}