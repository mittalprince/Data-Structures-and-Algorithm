// https://codeforces.com/contest/1374/problem/E1
#include<iostream>
#include<vector>
#include<algorithm>
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

int main(){

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    ll n,k;
    cin>>n>>k;
    
    priority_queue<ll, vector<ll>, greater<ll> >pa, pb, pab;
    ll ct1=0, ct2=0;
    ll t;
    bool a,b;
    for(ll i=0; i<n; i++){
        cin>>t>>a>>b;
        if(a and b){
            pab.push(t);
            ct1++;
            ct2++;
        }
        else if(a){
            pa.push(t);
            ct1++;
        }
        else if(b){
            pb.push(t);
            ct2++;
        }
    }

    if(ct1<k or ct2<k){
        cout<<"-1\n";
        return 0;
    }

    ll ans=0;
    ll ct=0;

    while(ct<k and !pa.empty() and !pb.empty() and !pab.empty()){
        ll pa_top = pa.top();
        ll pb_top = pb.top();
        ll pab_top = pab.top();

        if(pab_top < (pa_top+pb_top)){
            ans += pab_top;
            pab.pop();
        }
        else{
            ans += pa_top+pb_top;
            pa.pop();
            pb.pop();
        }
        ct++;
    }
    
    if(ct==k){
        cout<<ans<<endl;
        return 0;
    }

    if(pa.empty() or pb.empty()){
        while(ct<k and !pab.empty()){
            ans += pab.top();
            pab.pop();
            ct++;
        }
        cout<<ans<<endl;
        return 0;
    }

    if(pab.empty()){
        while(ct<k and !pa.empty() and !pb.empty()){
            ans += pa.top()+pb.top();
            pa.pop();
            pb.pop();
            ct++;
        }
        cout<<ans<<endl;
    }

    return 0;
}