// https://leetcode.com/problems/shortest-common-supersequence/
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

string shortestCommonSupersequence(string a, string b) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n=a.size();
    int m=b.size();
    vector<vector<int>>dp(n+1, vector<int>(m+1, 0));

    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            if(a[i-1] == b[j-1]){
                dp[i][j] = 1+dp[i-1][j-1];
            } else {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }

    int i=n, j=m;
    string ans="";
    // print lcs with some modification
    while(i>0 && j>0){
        if(a[i-1] == b[j-1]){
            ans += a[i-1];
            i--;
            j--;
        } else if(dp[i-1][j] > dp[i][j-1]){
            ans += a[i-1]; // extra thing we're doing
            i--;
        } 
        else {
            ans += b[j-1];
            j--;
        }
    }
    while(i>0){
        ans += a[i-1];
        i--;
    }
    while(j>0){
        ans += b[j-1];
        j--;
    }
    reverse(ans.begin(), ans.end());
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