// https://leetcode.com/problems/implement-queue-using-stacks/
#include<iostream>
#include<vector>
#include<stack>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define ip1(arr, n) for(int i=1; i<=n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define debug(x) cout<<x<<"\n";
#define inf 1e9
#define INF 1e16
#define MOD 1000000007

class MyQueue {
public:
    /** Initialize your data structure here. */
    stack<int> s1, s2;
    int front, size;
    
    MyQueue() {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
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

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */

int main(){

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    int n;
    cin>>n;
    vector<int> arr(n);
    
    return 0;
}