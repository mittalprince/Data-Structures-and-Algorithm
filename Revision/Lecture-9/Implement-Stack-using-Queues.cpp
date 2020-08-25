// https://leetcode.com/problems/implement-stack-using-queues/
#include<iostream>
#include<vector>
#include<queue>
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

class MyStack {
public:
    /** Initialize your data structure here. */
    queue<int> q1, q2;
    int mytop, size;
    
    MyStack() {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
            
        mytop=-1;
        size=0;
    }
    
    /** Push element x onto stack. */
    void push(int x) {
        q1.push(x);
        mytop=x;
        size++;
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        if(size==1){
            int ans=q1.front();
            q1.pop();
            size--;
            return ans;
        }
        else if(size>1){
            while(q1.size()>2){
                q2.push(q1.front());
                q1.pop();
            }
            mytop=q1.front();
            q2.push(mytop);
            q1.pop();
            
            int last=q1.front();
            q1.pop();
            while(!q2.empty()){
                q1.push(q2.front());
                q2.pop();
            }
            size--;
            return last;
        }
        return 0;
    }
    
    /** Get the top element. */
    int top() {
        return mytop;
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return (size==0);
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
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