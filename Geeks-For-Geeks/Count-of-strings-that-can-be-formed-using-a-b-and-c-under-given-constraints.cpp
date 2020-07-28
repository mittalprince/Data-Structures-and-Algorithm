#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);

void solve(){
    int n;
    cin>>n;

    ll dp[1005][2][3]={0};
    // state -> n,bcount,ccount

    for(int i=0; i<=n; i++){
        for(int b=0; b<2; b++){
            for(int c=0; c<3; c++){
                if(i==0){
                    dp[0][b][c]=1;
                    continue;
                }
                ll ans = dp[i-1][b][c];
                if(b>0){
                    ans += dp[i-1][b-1][c];
                }
                if(c>0){
                    ans += dp[i-1][b][c-1];
                }
                dp[i][b][c] = ans;
            }
        }
    }
    cout<<dp[n][1][2]<<endl;
}

int main(){
    int t;
    cin>>t;
     while(t--){
         solve();
    }
    return 0;
}