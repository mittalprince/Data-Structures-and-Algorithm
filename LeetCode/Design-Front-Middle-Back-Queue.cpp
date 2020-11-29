//https://leetcode.com/problems/design-front-middle-back-queue/
#include<iostream>
#include<vector>
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

class FrontMiddleBackQueue {
public:
    vector<int>v;
    
    FrontMiddleBackQueue() {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        
    }
    
    void pushFront(int val) {
        v.insert(v.begin(), val);
    }
    
    void pushMiddle(int val) {
        v.insert(v.begin()+v.size()/2, val);
    }
    
    void pushBack(int val) {
        v.push_back(val);
    }
    
    int popFront() {
        if(v.empty())return -1;
        int ans = v[0];
        v.erase(v.begin());
        return ans;
    }
    
    int popMiddle() {
        if(v.empty())return -1;
        int ans = v[(v.size()-1)/2];
        v.erase(v.begin()+(v.size()-1)/2);
        return ans;
    }
    
    int popBack() {
        if(v.empty())return -1;
        int ans=v.back();
        v.pop_back();
        return ans;
    }
};

/**
 * Your FrontMiddleBackQueue object will be instantiated and called as such:
 * FrontMiddleBackQueue* obj = new FrontMiddleBackQueue();
 * obj->pushFront(val);
 * obj->pushMiddle(val);
 * obj->pushBack(val);
 * int param_4 = obj->popFront();
 * int param_5 = obj->popMiddle();
 * int param_6 = obj->popBack();
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