#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define MAX 2005

ll n,h,l,r;
ll arr[MAX];
ll dp[MAX][MAX];
// dp[i][j] -> max no of good sleep we have after the ith sleep and woke up at hour j

ll solve(ll sleep, ll waking_hr){
    if(sleep == n){
        return 0; // we have considered all sleeps and now there is no googd sleep, so return 0
    }
    if(dp[sleep][waking_hr] != -1) return dp[sleep][waking_hr];

    ll x = (arr[sleep]+waking_hr)%h;
    ll y = (arr[sleep]-1+waking_hr)%h;

    ll opt1 = solve(sleep+1, x) + (x>=l && x<=r);
    ll opt2 = solve(sleep+1, y) + (y>=l && y<=r);

    dp[sleep][waking_hr]= max(opt1,opt2);
    return dp[sleep][waking_hr];
}
int main(){
    cin>>n>>h>>l>>r;
    ip(arr, n);
    memset(dp, -1, sizeof(dp));
    cout<<solve(0,0)<<endl;
    return 0;
}