#include<iostream>
#include<vector>
#include<cstring>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define MOD 1000000007

int primes[15]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47};

ll dp[55][(1<<15)+1], arr[55];
ll n;

ll solve(ll i, ll mask){
    if(i == n || mask == (1<<15)) return 0;

    ll &res = dp[i][mask];
    if(res != -1) return res;

    if(arr[i] == 1){
        return res = 1+solve(i+1, mask);
    }

    res = solve(i+1, mask); // without considering curr element into subset
    for(int j=0; j<15; j++){
        if(arr[i]<primes[j]) break;
        if((arr[i]%primes[j]) == 0){
            if(mask&(1<<j)) return res;
            else mask |= (1<<j);
        }
    }
    res =max(res, 1+solve(i+1, mask)); // consider curr elemnt
    return res;
}

int main(){

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    int t;
    cin>>t;
    while(t--){
        cin>>n;
        ip(arr, n);
        memset(dp, -1, sizeof(dp));
        cout<<solve(0, 0)<<endl;
    }
    return 0;
}