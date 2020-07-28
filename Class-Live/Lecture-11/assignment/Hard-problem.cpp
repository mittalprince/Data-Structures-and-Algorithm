#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>
#include<climits>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define MAX 1e17+5
#define M 100005

int main(){
    ll dp[M][2]; // 2 column 1. when string is not reversed, 2. when string is reversed

    ll n;
    cin>>n;
    ll cost[n];
    ip(cost, n);
    vector<string> arr;
    for(int i=0; i<n; i++){
        string s;
        cin>>s;
        arr.push_back(s);
        dp[i][0]=dp[i][1] = MAX;
    }

    // dp[i][j] -> min cost req to make total i strings lexographically sorted and if j=0 means ith string in normal order otherwise in reverse order

    dp[0][0] = 0; // no operation (as string is not reverse)
    dp[0][1] = cost[0]; // when 0th sting reverse total cost is cost[0]

    for(int i=1; i<n; i++){
        /*
        Now I have two options
        1. if ith string is not reversed
            1. then comp ith string (i-1)th string
            2. comp ith string with (i-1)th string in reverse order
            dp[i][0] (take 0 as ith string is not reverses)
            dp[i][0] = min(dp[i-1][0], dp[i-1][1])

        2. if ith string is reversed (means j=1)
            1. then comp ith string (i-1)th string
            2. comp ith string with (i-1)th string in reverse order
            dp[i][1] (take 1 as ith string is reversed)
            dp[i][1] = min(dp[i-1][0]+cost[i], dp[i-1][1]+cost[i])
            // I add cost[i] as ith string is reversed
        */

       string prev_reversed = arr[i-1];
       reverse(prev_reversed.begin(), prev_reversed.end());

       string curr_reversed = arr[i];
       reverse(curr_reversed.begin(), curr_reversed.end());

        // first possibility -> ith string wihtout reversed
        if(arr[i]>=arr[i-1]){
           dp[i][0] = min(dp[i][0], dp[i-1][0]);
        }
        if(arr[i] >= prev_reversed){
           dp[i][0] = min(dp[i][0], dp[i-1][1]);
        }

        // second possibility -> ith string reversed
        if(curr_reversed >= arr[i-1]){
            dp[i][1] = min(dp[i][1], dp[i-1][0]+cost[i]);
        }
        if(curr_reversed >= prev_reversed){
            dp[i][1] = min(dp[i][1], dp[i-1][1]+cost[i]);
        }
    }

    ll ans = min(dp[n-1][0], dp[n-1][1]);
    if(ans != MAX) cout<<ans<<endl;
    else cout<<"-1\n";

    return 0;
}