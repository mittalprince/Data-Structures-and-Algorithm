// how to perform Merge sort using threads.
class SingleThreadedMergeSort{
    private static int[] scratch = new int[10];
    public static void main(String args[]){
        int[] input = new int[]{ 9, 8, 7, 6, 5, 4, 3, 2, 1, 0 };
        printArray(input, "Before: ");
        mergeSort(0, input.length-1, input);
        printArray(input, "After: ");
    }

    public static void mergeSort(int left, int right, int[] input){
        if(start == end) return;
        int mid = (left + right)/2;
        mergeSort(start, mid, input);
        mergeSort(mid + 1, right, input);

        int i=start;
        int j=mid+1;
        int k;

        for(k=start; k<=end; k++){
            scratch[k] = input[k];
        }
        k=start;
        while(k<=end){
            if(i<=mid && j<=end){
                input[k] = Math.min(scratch[i], scratch[j]);
                if (input[k] == scratch[i]) {
                    i++;
                } else {
                    j++;
                }
            } else if(i<=mid && j>end){
                input[k] = scratch[i];
                i++;
            } else {
                input[k] = scratch[j];
                j++;
            }
            k++;
        }
    }

    private static void printArray(int[] input, String msg){
        System.out.println();
        System.out.println(msg + " ");
        for(int i=0; i<input.length; i++){
            System.out.print(" " + input[i] + " ");
        }
        System.out.println();
    }
}


/*
Using Multithreading
We create two threads  and then wait for them to finish and then apply the merging
*/

import java.util.Random;

class Demonstration{
    private static int SIZE=25;
    private static Random random = new Random(System.currentTimeMillis());
    private static int[] input = new int[SIZE];

    static private void createTestData(){
        for(int i=0; i<SIZE; i++){
            input[i] = random.nextInt(10000);
        }
    }
    static private void printArray(int[] input) {
        System.out.println();
        for (int i = 0; i < input.length; i++)
            System.out.print(" " + input[i] + " ");
        System.out.println();
    }

    public static void main(String args[]){
        createTestData();
        System.out.println("Unsorted Array");
        printArray(input);
        long start = System.currentTimeMillis();
        (new MultiThreadedMergeSort()).mergeSort(0, input.length - 1, input);
        long end = System.currentTimeMillis();
        System.out.println("\n\nTime taken to sort = " + (end - start) + " milliseconds");
        System.out.println("Sorted Array");
        printArray(input);
    }
}

class MultiThreadedMergeSort {

    private static int SIZE = 25;
    private int[] input = new int[SIZE];
    private int[] scratch = new int[SIZE];

    void mergeSort(final int start, final int end, final int[] input) {

        if (start == end) {
            return;
        }

        final int mid = start + ((end - start) / 2);

        // sort first half
        Thread worker1 = new Thread(new Runnable() {

            public void run() {
                mergeSort(start, mid, input);
            }
        });

        // sort second half
        Thread worker2 = new Thread(new Runnable() {

            public void run() {
                mergeSort(mid + 1, end, input);
            }
        });

        // start the threads
        worker1.start();
        worker2.start();

        try {

            worker1.join();
            worker2.join();
        } catch (InterruptedException ie) {
            // swallow
        }

        // merge the two sorted arrays
        int i = start;
        int j = mid + 1;
        int k;

        for (k = start; k <= end; k++) {
            scratch[k] = input[k];
        }

        k = start;
        while (k <= end) {

            if (i <= mid && j <= end) {
                input[k] = Math.min(scratch[i], scratch[j]);

                if (input[k] == scratch[i]) {
                    i++;
                } else {
                    j++;
                }
            } else if (i <= mid && j > end) {
                input[k] = scratch[i];
                i++;
            } else {
                input[k] = scratch[j];
                j++;
            }
            k++;
        }
    }
}


