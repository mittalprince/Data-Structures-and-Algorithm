#include<iostream>
#include<vector>
#include<queue>
#include<cmath>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define MAX 35

int n,k;
ll arr[MAX];
ll K_Max_Val = 0;

ll fstPower(ll a, ll b){
    ll ans=a;
    while(b){
        if(b&1){
            ans = ans*a;
        }
        a *= a;
        b /= 2;
    }
    return ans;
}

void solve(){
    cin>>n>>k;
    priority_queue<ll>pq;
    for(int i=0; i<n; i++){
        cin>>arr[i];
        if(arr[i]>0) pq.push(arr[i]);
    }

    ll k_max_val = fstPower(k, (16/log10(k)));

    while(!pq.empty() && k_max_val>0){
        if(pq.top() >= k_max_val){
            ll top = pq.top();
            pq.pop();
            top -= k_max_val;
            if(top) pq.push(top);
        }
        k_max_val /= k;
    }

    if(pq.empty()) cout<<"YES\n";
    else cout<<"NO\n";
}

int main(){
    int t;
    cin>>t;
     while(t--){
         solve();
    }
    return 0;
}