#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define MAX 100005
#define mod 1000000007
#define endl "\n"
long long dp[MAX]={0};

void solve(){
    dp[1]=1; dp[2]=2;

    for(int i=3; i<MAX; i++){
        dp[i] = (dp[i-2]+dp[i-1])%mod;
    }
}

int main(){
    fstIO;
    int t;
    cin>>t;
    solve();
     while(t--){
         int n;
         cin>>n;
         cout<<dp[n]<<endl;
    }
    return 0;
}