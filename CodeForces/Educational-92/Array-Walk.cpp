// https://codeforces.com/contest/1389/problem/B
#include<iostream>
#include<vector>
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

void solve(){
    ll n,k,z;
    cin>>n>>k>>z;

    vector<ll>arr(n);
    ip(arr, n);

    vector<ll>prefix(n, 0), adjacentSum(n, 0);
    for(ll i=1; i<n; i++){//prefix sum nikal liya ki ith index tak elemnt ka sum kitna hai
        prefix[i] += prefix[i-1]+arr[i];
    }

    for(ll i=1; i<n; i++){ // we cal adjancent sum at each index
    // this will help when we want to perform left operation, then we need to just find howm nay times
    // we can perform left operaation then we just multiply this with adjacentSum val, because it will tell
    // the ek left operation se ans mein kitna add hoga
        adjacentSum[i] = arr[i]+arr[i-1];
    }

    ll ans=0, leftMove;
    for(ll i=1; i<=k; i++){// har ith operation par hum check karnege ki agee right jaye ya left.  
        leftMove = min(z, (k-i+1)/2); // check ki har point par kitne left move le sakta hoo
        ll sum = leftMove*adjacentSum[i]+prefix[k-(2*leftMove)]; // k-(2*leftMove) isliye ki agr hum leftMove karta hai toh uska sath ek right move toh hoga hi
        // so it will add 2 operation, so now how many operation availble we just add their prefix sum
        // cout<<prefix[k]<<endl;
        ans = max(ans, sum);
    }
    ans += arr[0];
    cout<<ans<<endl;
}

int main(){

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}