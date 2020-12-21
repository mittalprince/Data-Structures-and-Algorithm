//https://leetcode.com/problems/jump-game-vi/
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

maxResult(vector<int>& nums, int k) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 

    long curr=0;
    deque<int>dq;

    int n=nums.size();
    for(int i=n-1; i>=0; i--){
        curr = nums[i]+(dq.empty()?0: nums[dq.front()]);

        while(!dq.empty() and nums[dq.back()]<curr){
            dq.pop_back();
        }
        dq.push_back(i);

        if(dq.front()>=i+k)dq.pop_front();
        nums[i]=curr;
    }
    return nums[0];
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