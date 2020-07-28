#include<iostream>
#include<vector>
#include<cstring>
#include<iomanip>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=1; i<=n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define MAX 3000

ll n;
double arr[MAX];
double dp[MAX][MAX];
// dp[i][j] -> probability of getting j heads with i coins tosses.

double solve(int coins, int heads_req){
    if(heads_req == 0){//now we req 0 head, so to get 0 heads out of 0 or more coins is always 1
        return 1;
        // assume mera pass 5 coins hai mein toss kiya unse kinte aise coins honge jisme kam se kam 
        // 0 head aya hoo (matlab head ho ya na ho koi farak nahu padta) sare coins hi honge
        // so it will give 1
    }
    if(coins == 0){// now we don't have any coins, but still we need more head_req heads
        return 0;
        // basically assume tera pass 0 coins hai and tune unhe toss kiya abb head_req head ane ki
        // possibility kya hogi, 0 qki coins hi nahi rahe toh head hi nahi a sakte
    }

    if(dp[coins][heads_req] > -1) return dp[coins][heads_req];

    double opt1 = arr[coins]*solve(coins-1, heads_req-1);
    double opt2 = (1-arr[coins])*solve(coins-1, heads_req);

    dp[coins][heads_req]=opt2+opt1;
    return dp[coins][heads_req];
}
// complxityy o(N^2)

int main(){
    cin>>n;
    ip(arr, n);
    memset(dp, -1, sizeof(dp));
    cout<<fixed<<setprecision(11)<<solve(n, (n+1)/2)<<endl;
    return 0;
}