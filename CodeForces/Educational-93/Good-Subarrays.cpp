// https://codeforces.com/contest/1398/problem/C
#include<iostream>
#include<vector>
#include<map>
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

/*
Sum(i to j) - (j-i+1) =0  
now, to perform this LHS part in the subarray, you need to subtract (j-i+1) from total sum, 
or if you subtract exactly one unit from each element , then u r done with reducing (i-j+1) 
from the total sum of elements, as we have supposed  that subarray was of length (j-i+1) only.
*/

void solve(){
    ll n;
    cin>>n;
    string s;
    cin>>s;
    map<ll, ll>m;
    m[0]=1;
    ll ans=0;
    ll sum=0;
    for(ll i=0; i<n; i++){
        ll val = s[i]-'0';
        val--;
        sum += val;
        ans += m[sum];
        m[sum]++;
    }
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