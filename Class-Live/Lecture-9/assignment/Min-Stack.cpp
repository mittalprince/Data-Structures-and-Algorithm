#include<iostream>
#include<vector>
#include<stack>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);

class MinStack {
public:
    stack<pair<int, int>>s;
    
    MinStack() {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
    }
    
    void push(int x) {
        int m;
        if(s.empty()) m=x;
        else{
            m = min(x, s.top().second);
        }
        s.push({x, m});
    }
    
    void pop() {
        if(s.empty()) return;
        s.pop();
    }
    
    int top() {
        return s.top().first;
    }
    
    int getMin() {
        return s.top().second;
    }
};

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    
    return 0;
}