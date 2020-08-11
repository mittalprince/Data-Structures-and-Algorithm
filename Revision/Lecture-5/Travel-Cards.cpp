// https://codeforces.com/problemset/problem/847/K
#include<iostream>
#include<vector>
#include<map>
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

void solve(){
    ll n,a,b,k,f;
    cin>>n>>a>>b>>k>>f;
    map<pair<string,string>, ll>m;
    string src, dest, prev="";

    for(int i=0; i<n; i++){
        cin>>src>>dest;
        ll price=0;
        if(src==prev){
            price=b;
        }
        else price=a;
        prev=dest;
        if(src>dest)swap(src, dest);
        m[{src, dest}] += price;
    }

    vector<ll>cost;
    ll total_cost=0;
    for(auto it:m){
        cost.push_back(it.second);
        total_cost += it.second;
    }

    sort(cost.rbegin(), cost.rend());
    for(int i=0; i<k and i<cost.size(); i++){
        if(cost[i]>=f){
            total_cost += (f-cost[i]);
        }
        else break;
    }

    cout<<total_cost<<endl;
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