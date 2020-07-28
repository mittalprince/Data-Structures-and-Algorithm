#include<iostream>
#include<vector>
#include<stack>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);

class MyQueue {
public:
    /** Initialize your data structure here. */
    stack<int> s1, s2;
    int front, size;
    MyQueue() {
        front=-1;
        size=0;
    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        if(s1.empty()) front=x;
        s1.push(x);
        size++;
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        if(size==1){
            int ans=s1.top();
            s1.pop();
            size--;
            return ans;
        }
        else if(size>1){
            while(s1.size()>2){
                s2.push(s1.top());
                s1.pop();
            }
            front=s1.top();
            s2.push(front);
            s1.pop();
            int ans=s1.top();
            s1.pop();
            while(!s2.empty()){
                s1.push(s2.top());
                s2.pop();
            }
            size--;
            return ans;
        }
        return 0;
    }
    
    /** Get the front element. */
    int peek() {
        return front;
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return (size==0);
    }
};

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    
    return 0;
}