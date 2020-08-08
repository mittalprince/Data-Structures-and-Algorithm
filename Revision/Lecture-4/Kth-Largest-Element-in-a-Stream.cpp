// https://leetcode.com/problems/kth-largest-element-in-a-stream/
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

class KthLargest {
public:
    priority_queue<int, vector<int>, greater<int> >pq;
    int size;
    
    KthLargest(int k, vector<int>& nums) {
        pq = priority_queue<int, vector<int>, greater<int> >();
        size=k;
        for(auto iter:nums)
        {
            add(iter);
        }
    }
    
    int add(int x) {
        if(size>pq.size()){
            pq.push(x);
            return pq.top();
        }
        else{
            if(pq.top()<=x){
                pq.pop();
                pq.push(x);
            }
            return pq.top();
        }
    }
};

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