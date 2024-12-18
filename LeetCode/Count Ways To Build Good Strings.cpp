// https://leetcode.com/problems/count-ways-to-build-good-strings/
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

int countGoodStrings(int low, int high, int zero, int one) {
    int dp[100005]={0};
    const int mod = 1000000007;
    dp[0]=1;
    int ans=0;
    for(int i=1; i<=high; i++){
        if(i>=one) dp[i] = (dp[i]+dp[i-one])%mod;
        if(i>=zero) dp[i] = (dp[i]+dp[i-zero])%mod;
        if (i>=low) ans = (ans + dp[i])%mod;
    }
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