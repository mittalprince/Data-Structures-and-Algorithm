//https://leetcode.com/problems/restore-the-array/
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

int solve(vector<int>&dp, string& s, int k, int i){
    if (i == s.length())return 1;
    if (s[i] == '0') return 0;
    if (dp[i] != -1) return dp[i];

    int ans = 0;
    long num = 0;
    for(int j=i; j<s.length(); j++){
        num = num*10 + (s[j] - '0');
        if (num > k) break;
        ans += solve(dp, s, k, j+1);
        ans %= 1000000007;
    }
    return dp[i] = ans;
}
int numberOfArrays(string s, int k) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    /*
    vector<int>dp(s.length(), -1);
    return solve(dp, s, k, 0);
    */
    int len = s.length();
    vector<int> dp(len+1, 0);
    dp[len] = 1;
    for(int i=len-1;i>=0;i--) {
        if(s[i] == '0') {
            dp[i] = 0;
            continue ;
        }
        long ans = 0, x = 0;
        for(int j=i;j<len;j++) {
            x = x*10+s[j]-'0';
            if(x > k) break; 
            ans += dp[j+1];
            ans = ans%1000000007;
        }
        dp[i] = ans;
    }
    return dp[0];
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