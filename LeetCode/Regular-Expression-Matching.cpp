//https://leetcode.com/problems/regular-expression-matching/
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

bool isMatch(string s, string p) {
    int m=p.size();
    int n=s.size();

    bool dp[2001][2001]={0};
    dp[0][0]=1;

    for(int i=1; i<=m; i++){
        if(p[i-1] == '*') dp[0][i] = dp[0][i-2];
    }
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            if(p[j-1] == '*'){
                dp[i][j] = dp[i][j-2];
                if(!dp[i][j] && ((s[i-1] == p[j-2]) || p[j-2] == '.')){
                    dp[i][j] = dp[i][j] || dp[i-1][j];
                }   
            }
            else if(s[i-1] == p[j-1] || p[j-1] == '.'){
                dp[i][j] = (dp[i-1][j-1]);    
            }
        }
    }
    return dp[n][m];
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