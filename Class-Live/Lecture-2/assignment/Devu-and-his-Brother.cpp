#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;

bool comp(ll a, ll b){
    return a>b;
}
int main(){
    ll n,m;
    cin>>n>>m;
    ll arr[n], brr[m];
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    for(int j=0; j<m; j++){
        cin>>brr[j];
    }
    sort(arr, arr+n);
    sort(brr, brr+m, comp);
    ll ans=0;
    ll idx = min(n,m);
    for(ll i=0; i<idx; i++){
        if(brr[i]>arr[i]){
            ans += (brr[i]-arr[i]);
        }
    }
    cout<<ans<<endl;
}