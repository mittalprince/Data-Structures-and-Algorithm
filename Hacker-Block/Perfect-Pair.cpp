#include<iostream>
#include<vector>
#include<unordered_map>
#include<cstring>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define MOD 1000000007
#define N 15

ll countPairs(int n, int arr[]){
    unordered_map<int, int>hash;
    ll dp[(1<<N)][N+1];

    memset(dp, 0, sizeof(dp));

    for(int i=0; i<n; i++){
        hash[arr[i]]++;
    }

    for(ll mask=0; mask< (1<<N); mask++){
        if(mask&1){
            dp[mask][0] = hash[mask] + hash[mask^1];
        }
        else dp[mask][0] = hash[mask];

        for(int j=1; j<=N; j++){
            if(mask&(1<<j)){
                dp[mask][j] = dp[mask][j-1]+dp[mask^(1<<j)][j-1];
            }
            else dp[mask][j] = dp[mask][j-1];
        }
    }

    ll ans=0;
    for(int i=0; i<n; i++){
        ans += dp[(1<<N)-1^arr[i]][N];
    }
    // cout<<ans<<endl;
    return ans;
}

int main(){

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    int n;
    cin>>n;
    int arr[n];
    ip(arr, n);
    cout<<countPairs(n, arr)<<endl;
    return 0;
}