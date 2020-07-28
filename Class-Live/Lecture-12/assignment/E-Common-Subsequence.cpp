#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define mod 1000000007
#define MAX 10005

ll s[MAX], t[MAX];
ll n, m;

void sovle(){
    vector<vector<ll> >dp(n+1, vector<ll>(m+1, 0));

    // dp[i][j] -> total no of comom seq upto ith index of s and jth index og t
    ll ans=0;

    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            // when (i-1) & (j-1)th of s and t match then
            // dp[i][j] will be total common seq upto (i, j-1)(i.e without conisdering jth element of t)
            // and (i-1, j)(i.e without conisdering ith element of s)
            // and plus 1 as ith and jth element match, so it also common seq
            if(s[i-1] == t[j-1]){
                dp[i][j] = (dp[i-1][j]%mod + dp[i][j-1]%mod +1)%mod;
            }

            // we sub dp[i-1][j-1] as it already include in both (i-1,j)&(i,j-1)
            else dp[i][j] = (dp[i-1][j]%mod +dp[i][j-1]%mod -dp[i-1][j-1]%mod +mod)%mod;
        }
    }
    cout<<(dp[n][m]+1)%mod<<endl; // add plus one for when both string are empty
}
int main(){
    cin>>n>>m;
    ip(s, n);
    ip(t, m);
    sovle();
    return 0;
}