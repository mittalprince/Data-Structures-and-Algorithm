#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);

class MyCircularQueue {
public:
    vector<int>arr;
    int front, total_elemt, size;
    /** Initialize your data structure here. Set the size of the queue to be k. */
    MyCircularQueue(int k) {
        arr.resize(k);
        front=0;
        total_elemt=0;
        size=k;
    }
    
    /** Insert an element into the circular queue. Return true if the operation is successful. */
    bool enQueue(int value) {
        if(!isFull()){
            arr[(front+total_elemt)%size] = value;
            total_elemt++;
            return true;
        }
        return false;
    }
    
    /** Delete an element from the circular queue. Return true if the operation is successful. */
    bool deQueue() {
        if(!isEmpty()){
            front = (front+1)%size;
            total_elemt--;
            return true;
        }
        return false;
    }
    
    /** Get the front item from the queue. */
    int Front() {
        return isEmpty()?-1: arr[front];
    }
    
    /** Get the last item from the queue. */
    int Rear() {
        return isEmpty()?-1: arr[(front+total_elemt-1)%size];
    }
    
    /** Checks whether the circular queue is empty or not. */
    bool isEmpty() {
        return total_elemt == 0;
    }
    
    /** Checks whether the circular queue is full or not. */
    bool isFull() {
        return (total_elemt == size);
    }
};

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    
    return 0;
}