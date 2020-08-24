// https://leetcode.com/problems/kth-largest-element-in-an-array/
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

int findKthLargest(vector<int>& nums, int k) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    priority_queue<int, vector<int>, greater<int> >pq;

    for(int i=0; i<nums.size(); i++){
        if(i<k){
            pq.push(nums[i]);
        }
        else{
            if(pq.top()<=nums[i]){
                pq.pop();
                pq.push(nums[i]);
            }
        }
    }
    return pq.top();
}

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