#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);

void solve(){
    ll n,a,b,k,f;
    cin>>n>>a>>b>>k>>f;
    string src, dest, prev="";
    map<pair<string, string>, ll> m;
    for(ll i=0; i<n; i++){
        cin>>src>>dest;
        ll price=0;
        if(prev == src){
            price =b;
        }
        else price=a;
        prev = dest;
        if(src>dest){
            swap(src,dest);
        }
        m[{src, dest}]+=price;
    }
    vector<ll> cost;
    ll total_cost=0;
    for(auto i: m){
        cost.push_back(i.second);
        total_cost += i.second;
    }
    sort(cost.rbegin(), cost.rend());
    for(ll i=0; i<cost.size() && i<k; i++){
        // we purchase pass for each travel which has cost >= f
        if(cost[i]>=f){
            total_cost += (f-cost[i]);
        }
        else break; // since given cost is less than f, then all cost right to it also small as vector is sorted revese
    }
    cout<<total_cost<<endl;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}