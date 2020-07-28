#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);

class MyCircularQueue {
public:
    int *arr;
    int size, capacity, front, rear;
    /** Initialize your data structure here. Set the size of the queue to be k. */
    MyCircularQueue(int k) {
        arr = new int[k];
        size=k;
        capacity=0;
        front=0;
        rear = size-1;
    }
    
    /** Insert an element into the circular queue. Return true if the operation is successful. */
    bool enQueue(int value) {
        if(capacity == size) return false;
        rear = (rear+1)%size;
        arr[rear]=value;
        capacity++;
        return true;
    }
    
    /** Delete an element from the circular queue. Return true if the operation is successful. */
    bool deQueue() {
        if(capacity == 0) return false;
        front = (front+1)%size;
        capacity--;
        return true;
    }
    
    /** Get the front item from the queue. */
    int Front() {
        if(capacity == 0) return -1;
        return arr[front];
    }
    
    /** Get the last item from the queue. */
    int Rear() {
        if(capacity == 0) return -1;
        return arr[rear];
    }
    
    /** Checks whether the circular queue is empty or not. */
    bool isEmpty() {
        return capacity == 0;
    }
    
    /** Checks whether the circular queue is full or not. */
    bool isFull() {
        return capacity == size;
    }
};

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    
    return 0;
}