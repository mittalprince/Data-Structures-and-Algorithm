//https://leetcode.com/problems/minimum-ascii-delete-sum-for-two-strings/
#include<iostream>
#include<vector>
#include<cstring>
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

int minimumDeleteSum(string s1, string s2) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int len1 = s1.length();
    int len2 = s2.length();
    int maxl = 0;
    int dp[len1+1][len2+1];
    memset(dp, 0, sizeof(dp));
    for(int i = 0; i < len1; i++) {
        for(int j = 0; j < len2; j++) {
            if(s1[i] == s2[j]) {
                dp[i+1][j+1] = dp[i][j] + (s1[i]);
                maxl = max(maxl, dp[i+1][j+1]);
            }else{
                dp[i+1][j+1] = max(dp[i][j + 1], dp[i+1][j]);
            }
        }
    }

    int out = 0;
    for(int i = 0; i < s1.length(); i++) {
        out += int(s1[i]);
    }
    for(int i = 0; i < s2.length(); i++) {
        out += int(s2[i]);
    }

    return out - 2*maxl;
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