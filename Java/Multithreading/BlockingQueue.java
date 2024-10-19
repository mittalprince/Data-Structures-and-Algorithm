class Demonstration {
    public static void main(String agrs[]) throws Exception{
        final BlockingQueue<Integer> q = new BlockingQueue<Integer>(5);
        Thread t1 = new Thread(new Runnable(){
            @Override
            public void run(){
                try{
                    for(int i=0; i<50; i++){
                        q.enqueue(new Integer(i));
                        System.out.println("enqueued " + i);
                    }
                } catch (InterruptedException ie) {

                }
            }
        });

        Thread t2 = new Thread(new Runnable(){
            @Override
            public void run(){
                try{
                    for (int i = 0; i < 25; i++) {
                        System.out.println("Thread 2 dequeued: " + q.dequeue());
                    }
                } catch (InterruptedException ie) {

                }
            }
        });
        Thread t3 = new Thread(new Runnable(){
            @Override
            public void run(){
                try{
                    for (int i = 0; i < 25; i++) {
                        System.out.println("Thread 3 dequeued: " + q.dequeue());
                    }
                } catch (InterruptedException ie) {

                }
            }
        });

        t1.start();
        Thread.sleep(4000);
        t2.start();

        t2.join();

        t3.start();
        t1.join();
        t3.join();
    }
}

class BlockingQueue<T> {
    T[] array;
    Object lock = new Object();
    int size = 0;
    int capacity;
    int head = 0;
    int tail = 0;

    public BlockingQueue(int capacity){
        array = (T[]) new Object[capacity];
        this.capacity = capacity;
    }

    public void enqueue(T item) throws InterruptedException{
        synchronized (lock){
            while(size == capacity){
                lock.wait();
            }
            if(tail == capacity){
                tail = 0;
            }
            array[tail] = item;
            size++;
            tail++;
            lock.notifyAll();
        }
    }

    public T dequeue() throws InterruptedException {
        T item = null;
        synchronized (lock){
            if(size == 0){
                lock.wait();
            }
            if(head == capacity){
                head = 0;
            }
            item = array[head];
            array[head] = null;
            head++;
            size--;

            lock.notifyAll();
        }
        return item;
    }
}

/*
In both the enqueue() and dequeue() methods we use the notifyAll() method instead of the notify() method.
The reason behind the choice is very crucial to understand. Consider a situation with two producer threads
and one consumer thread all working with a queue of size one. It’s possible that when an item is added to the queue
by one of the producer threads, the other two threads are blocked waiting on the condition variable.
If the producer thread after adding an item invokes notify() it is possible that the other producer thread
is chosen by the system to resume execution. The woken-up producer thread would find the queue full and
go back to waiting on the condition variable, causing a deadlock. Invoking notifyAll() assures that the consumer
thread also gets a chance to wake up and resume execution.
*/
