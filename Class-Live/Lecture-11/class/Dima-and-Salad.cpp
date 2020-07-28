#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define Shift 100000
#define MAX 100000+1

ll n,k;
ll *taste, *calories;
ll dp[101][MAX];

// dp[i][j] -> max val of taste we have if we have consider total i items and we have this um till now
/*
(t[0]-k*cal[0])+(t[1]-k*cal[1])+(t[2]-k*cal[2])+...+(t[3]-k*cal[3]) = 0;
we have to take statisfy above condition sich that summition of all taste[i] will be max

so we have to two option either take ith item or not like knapsack
1. if we done take we just incr i and sum will remain same and call recur
2. if we take ith item we will add (t[0]-k*cal[0]) into sum(as in base we check when we reach at end our sum is 0 or not)
   (since this condition given in question) and if we take ith item taste[i] will include in ans

then we choose max of these two options
*/

ll DimaAndSalad(ll n, ll i, ll sum){
    // base case
    if(i==n){
        if(sum == 0) return 0;//we have considered all items and fpr no element max and will be 0
        else return -1e12; // since our sum!=0 menas condition not satisfied so it can be ans return val that is very small
    }

    if(dp[i][sum+Shift] != -1) return dp[i][sum+Shift];

    ll opt1 = DimaAndSalad(n, i+1, sum);
    ll opt2 = DimaAndSalad(n, i+1, sum+(taste[i]-k*calories[i]))+taste[i];
    dp[i][sum+Shift] = max(opt1, opt2);
    return dp[i][sum+Shift];
}
int main(){
    cin>>n>>k;
    taste = new ll[n];
    calories = new ll[n];
    
    ip(taste, n);
    ip(calories, n);

    memset(dp, -1, sizeof(dp));
    ll ans = DimaAndSalad(n, 0, 0);
    if(ans) cout<<ans<<endl;
    else cout<<"-1\n";

    return 0;
}