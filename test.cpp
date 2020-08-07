#include<iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<climits>
#include<cmath>
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

unordered_map<ll, ll>m;
ll n;

ll canPlace(){
    priority_queue<pair<ll, ll> >pq;
    for(auto it: m){
        pq.push({it.second, it.first});
    }

    unordered_map<ll, ll>t;
    ll i=0;

    ll ans=INT_MAX;

    while(!pq.empty()){
        ll size = pq.size();
        priority_queue<pair<ll, ll> >q;
        for(ll j=0; j<size; j++){
            auto top = pq.top();
            pq.pop();
            // cout<<top.second<<" "<<top.first<<endl;
            if(t.count(top.second)){
                // cout<<top.first<<" "<<i<<" "<<t[top.first]<<endl;
                ans = min(ans, i-t[top.second]-1);
            }
            t[top.second] = i;
            if(top.first>1){
                q.push({top.first-1, top.second});
            }
            i++;
        }
        pq=q;
    }

    if(ans == INT_MAX){
        ans = n-1;
    }
    return ans;
}

void solve(){
    cin>>n;
    vector<ll>arr(n);
    ip(arr, n);

    m.clear();
    
    for(ll i: arr){
        m[i]++;
    }
    if(m.size()==1){
        cout<<"0\n";
        return;
    }

    for(auto it: m){
        ll val = ceil((double)n/2);
        if(val<it.second){
            cout<<"0\n";
            return;
        }
        if(val == it.second){
            cout<<"1\n";
            return;
        }
    }

    cout<<canPlace()<<endl;
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