// https://www.hackerearth.com/practice/basic-programming/implementation/basics-of-implementation/practice-problems/algorithm/happy-numbers-4a67748e/description/?layout=old
#include<iostream>
#include<vector>
#include<algorithm>
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

vector<ll>v;

void solve(ll a){
    if(a>1e9)return;
    if(a != 0)v.push_back(a);
    solve(a*10+4);
    solve(a*10+7);
}

ll gcd(ll a, ll b){
    if(b==0)return a;
    return gcd(b, a%b);
}

int main(){

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    int n;
    cin>>n;
    
    solve(0);
    sort(v.begin(), v.end());

    ll ans=0;
    for(ll i=0; i<v.size() and v[i]<=n; i++){
        for(ll j=i+1; j<v.size() and v[j]<=n; j++){
            if(gcd(v[i], v[j])==1)ans++;
        }
    }
    cout<<ans<<endl;
    return 0;
}