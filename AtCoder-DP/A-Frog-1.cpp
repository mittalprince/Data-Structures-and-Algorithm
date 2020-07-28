#include<iostream>
#include<vector>
#include<cstring>
#include<climits>
#include<climits>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define MAX 100005

int n;
ll arr[MAX], dp[MAX]={0};

void bottomUp(){
    dp[1] = abs(arr[1]-arr[0]);
    
    for(int i=2; i<n; i++){
        dp[i] = min(dp[i-1]+abs(arr[i]-arr[i-1]), dp[i-2]+abs(arr[i]-arr[i-2]));
    }
    cout<<dp[n-1]<<endl;
}

ll solve(int pos){
    if(pos >= n-1) return 0;

    if(dp[pos] != -1) return dp[pos];

    ll ans=INT_MAX;
    for(int i=1; i<=2 && (pos+i)<n; i++){
        ans = min(ans, abs(arr[pos]-arr[pos+i])+ solve(pos+i));
    }
    return dp[pos]=ans;
}

void topDown(){
    memset(dp, -1, sizeof(dp));
    cout<<solve(0)<<endl;
}

int main(){
    cin>>n;
    ip(arr, n);
    // bottomUp();
    topDown();
    return 0;
}