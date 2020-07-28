#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);

class Pair{
    public:
    ll wt, cost;
    double cpw;

    Pair(ll w, ll c){
        wt = w;
        cost = c;
        cpw = double((1.0*cost)/wt);
        // cout<<wt<<" "<<cpw<<endl;
    }
};

int main(){
    ll n,l;
    cin>>n>>l;
    vector<Pair>arr;

    for(int i=0; i<n; i++){
        ll cost, wt;
        cin>>cost;
        wt = (1<<i);
        Pair t(wt, cost);
        arr.push_back(t);
    }

    sort(arr.begin(), arr.end(), [](const Pair &a, const Pair &b){
        return a.cpw < b.cpw;
    });

    ll curr_cost=0, ans=LLONG_MAX;
    for(ll i=0; i<n; i++){
        curr_cost += (l/(arr[i].wt))*arr[i].cost;
        l %= arr[i].wt;
        ans = min(ans, curr_cost + (l>0)*arr[i].cost);
    }
    
    cout<<ans<<endl;
    return 0;
}