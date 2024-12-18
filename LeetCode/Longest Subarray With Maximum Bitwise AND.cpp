// https://leetcode.com/problems/longest-subarray-with-maximum-bitwise-and/
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

int longestSubarray(vector<int>& nums) {
    int cand=*max_element(nums.begin(), nums.end());
    int ans=0, ct=0;
    for(int i: nums){
        if (cand == i) ct++;
        else {
            ans = max(ans, ct);
            ct=0;
        }
    }
    ans = max(ans,ct);
    return ans;
}

int main(){

/*
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
*/

    int n;
    cin>>n;
    vector<int> arr(n);
    
    return 0;
}