// https://leetcode.com/problems/maximum-sum-obtained-of-any-permutation/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define ip1(arr, n) for(int i=1; i<=n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define debug(x) cout<<x<<"\n";
#define inf 1e9
#define INF 1e16

#define MOD 1000000007
typedef long long ll;

int maxSumRangeQuery(vector<int>& nums, vector<vector<int>>& requests) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n=nums.size();
    vector<ll>prefix(n, 0);

    for(vector<int>&r: requests){
        prefix[r[0]]++;
        if(r[1]!=n-1)prefix[r[1]+1]--;
    }

    for(int i=1; i<n; i++){
        prefix[i] += prefix[i-1];
    }
    sort(prefix.rbegin(), prefix.rend());
    sort(nums.rbegin(), nums.rend());

    ll ans=0;
    for(int i=0;i<n;i++){
        ll val = (nums[i]%MOD * prefix[i]%MOD)%MOD;
        ans += val;
        ans %= MOD;
    }

    return ans;
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