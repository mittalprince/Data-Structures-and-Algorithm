// https://www.codechef.com/problems/IPCTRAIN
#include<iostream>
#include<vector>
#include<set>
#include<queue>
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
    ll n,d;
    cin>>n>>d;
    ll start[n], lw[n], sad[n];
    vector<ll>lt(n, 0);

    priority_queue<pair<ll,ll> >pq;
    for(int i=0; i<n; i++){
        cin>>start[i]>>lw[i]>>sad[i];
        pq.push({sad[i], i});
    }

    set<ll>days_available;
    for(int i=1; i<=d; i++){
        days_available.insert(i);
    }

    while(!pq.empty()){
        auto top=pq.top();
        pq.pop();

        ll idx = top.second;
        ll lecture_start_day = start[idx];
        ll lecture_end_day = start[idx]+lw[idx]-1;

        for(int i=lecture_start_day; i<=lecture_end_day; i++){
            auto it = days_available.lower_bound(i);
            if(days_available.end()==it){
                break;
            }
            else{
                days_available.erase(it);
                lt[idx]++;
            }
        }
    }
    ll ans=0;
    for(int i=0; i<n; i++){
        ans += (lw[i]-lt[i])*sad[i];
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