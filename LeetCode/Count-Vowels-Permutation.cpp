//https://leetcode.com/problems/count-vowels-permutation/
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

const int mod = 1000000007;

int countVowelPermutation(int n) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<long>dp(5, 1);
    for(int i=1; i<n; i++){
        vector<long>t(5,0);
        t[0] = (dp[1]+dp[2]+dp[4])%mod;
        t[1] = (dp[0]+dp[2])%mod;
        t[2] = (dp[1]+dp[3])%mod;
        t[3] = (dp[2])%mod;
        t[4] = (dp[2]+dp[3])%mod;

        dp=t;
    }

    long ans=0;
    for(int i=0; i<5; i++){
        ans = (ans+dp[i])%mod;
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