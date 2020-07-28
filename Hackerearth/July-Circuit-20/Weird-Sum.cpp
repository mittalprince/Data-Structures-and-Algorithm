// https://www.hackerearth.com/practice/algorithms/dynamic-programming/2-dimensional/practice-problems/algorithm/weird-sum-1d2a0a2e/
#include<iostream>
#include<vector>
#include<cstring>
#include<climits>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define ip1(arr, n) for(int i=1; i<=n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define debug(x) cout<<x<<"\n";
#define inf 1e9
#define INF 1e16
#define MOD 1000000007
#define N 10005
#define K 1005

ll dp[K][N];
ll *arr;
ll n, m, k;

ll solve(ll i, ll item_taken){
    if(item_taken>k)return 0;
    if(i>n)return -1e16;

    if(dp[item_taken][i] != LLONG_MAX)return dp[item_taken][i];

    ll opt1 = solve(i+1, item_taken);
    ll opt2 = arr[i]*(item_taken%m)+solve(i+1, item_taken+1);

    return dp[item_taken][i] = max(opt1, opt2);
}

int main(){

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    fstIO;

    cin>>n>>k>>m;
    arr = new ll[n+1];

    for(int i=1; i<=n; i++){
        cin>>arr[i];
    }

    for(int i=0; i<K; i++){
        for(int j=0; j<N; j++){
            dp[i][j] = LLONG_MAX;
        }
    }
    cout<<solve(1,1)<<endl;
    return 0;
}