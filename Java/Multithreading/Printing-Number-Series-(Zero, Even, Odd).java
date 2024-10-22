/*
Suppose we are given a number _n_based on which a program creates the series 010203…0n. There are three threads t1, t2 and t3 which print a specific type of number from the series. t1 only prints zeros, t2 prints odd numbers and t3 prints even numbers from the series. The code for the class is given as follows:

class PrintNumberSeries {··

    public PrintNumberSeries(int n) {
        this.n = n;· ·
    }

    public void PrintZero() {· ·
    }
    public void PrintOdd() {· ·
    }
    public void PrintEven() {· ·
    }
}

The argument passed to semaphore’s constructor is the number of ‘permits’ available. For oddSem and evenSem, all acquire() calls will be blocked initially as they are initialized with 0. For zeroSem, the first acquire() call will succeed as it is intialized with 1.
We were told to use three threads in the problem statement but the solution can be achieved using two threads as well. Since zero is printed before every number, we do not need to dedicate a special thread for it. We can simply print a zero before printing every odd or even number.
*/

import java.util.concurrent.*;

class PrintNumberSeries {
    private int n;
    private Semaphore zeroSem, oddSem, evenSem;

    public PrintNumberSeries(int n) {
        this.n = n;
        zeroSem = new Semaphore(1);
        oddSem = new Semaphore(0);
        evenSem = new Semaphore(0);
    }

    public void PrintZero() {
        for (int i = 0; i < n; ++i) {
            try {
                zeroSem.acquire();
            }
            catch (Exception e) {
            }
            System.out.print("0");
            // release oddSem if i is even or else release evenSem if i is odd
            (i % 2 == 0 ? oddSem : evenSem).release();
        }
    }

    public void PrintEven() {
        for (int i = 2; i <= n; i += 2) {
            try {
                evenSem.acquire();
            }
            catch (Exception e) {
            }
            System.out.print(i);
            zeroSem.release();
        }
    }

    public void PrintOdd() {
        for (int i = 1; i <= n; i += 2) {
            try {
                oddSem.acquire();
            }
            catch (Exception e) {
            }
            System.out.print(i);
            zeroSem.release();
        }
    }
}

class PrintNumberSeriesThread extends Thread {

    PrintNumberSeries zeo;
    String method;

    public PrintNumberSeriesThread(PrintNumberSeries zeo, String method){
        this.zeo = zeo;
        this.method = method;
    }

    public void run() {
        if ("zero".equals(method)) {
            try {
                zeo.PrintZero();
            }
            catch (Exception e) {
            }
        }
        else if ("even".equals(method)) {
            try {
                zeo.PrintEven();
            }
            catch (Exception e) {
            }
        }
        else if ("odd".equals(method)) {
            try {
                zeo.PrintOdd();
            }
            catch (Exception e) {
            }
        }
    }
}

public class Main {

    public static void main(String[] args) {

        PrintNumberSeries zeo = new PrintNumberSeries(5);

        Thread t1 = new PrintNumberSeriesThread(zeo,"zero");
        Thread t2 = new PrintNumberSeriesThread(zeo,"even");
        Thread t3 = new PrintNumberSeriesThread(zeo,"odd");

        t2.start();
        t1.start();
        t3.start();

    }
}