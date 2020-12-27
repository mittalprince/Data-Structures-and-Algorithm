//https://leetcode.com/problems/decode-ways/
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

int numDecodings(string s) {
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);

   int L = s.length();
   vector<int> dp(L + 1);
   dp[0] = 1;
   for (int i = 1; i <= L; i++) {
        dp[i] = 0;
        if ((s[i - 1] - '0') > 0) dp[i] += dp[i-1];
        if (i - 2 < 0) continue;
        if (10 * (s[i-2] - '0') + (s[i-1] - '0') <= 26 && 10 * (s[i-2] - '0') + (s[i-1] - '0') > 0 && s[i-2] != '0')
            dp[i] += dp[i-2];
    }
   return dp[L];
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