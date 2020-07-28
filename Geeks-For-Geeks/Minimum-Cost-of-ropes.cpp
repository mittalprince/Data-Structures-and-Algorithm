#include<iostream>
#include<vector>
#include<queue>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);

ll minCost(vector<ll> cost){
    ll n=cost.size();
    if(n<=1) return 0;

    priority_queue<ll, vector<ll>, greater<ll> >pq;
    for(ll i=0; i<n; i++){
        pq.push(cost[i]);
    }
    ll total_min_cost=0;

    while(pq.size()>1){
        ll top1 = pq.top(); pq.pop();
        ll top2 = pq.top(); pq.pop();

        total_min_cost += (top1+top2);
        pq.push(top1+top2);
    }

    return total_min_cost;
}

void solve(){
    ll n;
    cin>>n;
    vector<ll>cost(n);
    ip(cost, n);
    cout<<minCost(cost)<<endl;
}

int main(){
    int t;
    cin>>t;
     while(t--){
         solve();
    }
    return 0;
}