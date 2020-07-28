// https://codeforces.com/contest/975/problem/B
#include<iostream>
#include<vector>
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

    vector<ll>arr(14, 0), brr;
    for(ll i=0; i<14; i++){
        cin>>arr[i];
    }
    ll ans=0;

    for(ll i=0; i<14; i++){
        if(arr[i]==0)continue;

        brr = arr;
        ll val = brr[i];
        brr[i]=0;

        for(ll j=0; j<14; j++){
            brr[j] += val/14;
        }
        val %= 14;
        ll k=i+1;
        while(val--){
            if(k==14)k=0;
            brr[k++]++;
        }

        ll curr=0;
        for(ll j=0; j<14; j++){
            if(brr[j]%2==0)curr+=brr[j];
        }
        ans = max(ans, curr);
    }
    cout<<ans<<endl;
    return 0;
}