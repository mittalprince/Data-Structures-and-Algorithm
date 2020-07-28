// https://codeforces.com/contest/1148/problem/D
#include<iostream>
#include<vector>
#include<algorithm>
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

int main(){

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    ll n,x,y;
    cin>>n;
    vector<pair<ll,ll> > arr, brr;
    map<pair<ll, ll>, ll>m;
    for(ll i=0; i<n; i++){
        cin>>x>>y;
        m[{x,y}]=i+1;
        if(x<y){
            arr.push_back({x,y});
        }
        else brr.push_back({x,y});
    }

    sort(arr.begin(), arr.end(), [&](const pair<ll, ll>&a, const pair<ll, ll>&b)->bool{
        return a.second>b.second;
    });
    sort(brr.begin(), brr.end(), [&](const pair<ll, ll>&a, const pair<ll, ll>&b)->bool{
        return a.second<b.second;
    });

    if(arr.size()>=brr.size()){
        cout<<arr.size()<<endl;
        for(pair<ll, ll>t: arr){
            cout<<m[t]<<" ";
        }
        cout<<endl;
    }
    else{
        cout<<brr.size()<<endl;
        for(pair<ll, ll>t: brr){
            cout<<m[t]<<" ";
        }
        cout<<endl;
    }
    return 0;
}