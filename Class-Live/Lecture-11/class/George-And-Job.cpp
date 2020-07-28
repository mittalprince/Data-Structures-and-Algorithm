#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define MAX 5001

ll n,m,k;
ll arr[MAX];
ll dp[MAX][MAX];
//dp[i][j] -> we have considered total i items and we still need k more seq, then dp[i][j] will tell max val we will 
// have till now

ll solve(ll i, ll ct_k){
    if(i>n-m || ct_k == k){
        return 0;
    }
    if(dp[i][ct_k] != -1) return dp[i][ct_k];

    //since we have two options 
    //1. conider the ith element and make m size range, and increment i to i+m (as we have taken m element) and incr ct_k
    //2. or not consider, simply increment i
    ll opt1=0, opt2=0;
    for(int j=i; j<i+m; j++){
        opt1 += arr[j];
    }
    opt1 += solve(i+m, ct_k+1);
    opt2 = solve(i+1, ct_k);

    dp[i][ct_k] = max(opt1, opt2);
    return dp[i][ct_k];
}
int main(){
    cin>>n>>m>>k;
    ip(arr, n);
    memset(dp, -1, sizeof(dp));
    cout<<solve(0, 0)<<endl;
    return 0;
}