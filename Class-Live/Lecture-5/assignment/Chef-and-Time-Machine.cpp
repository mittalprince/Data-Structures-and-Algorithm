#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);

bool comp(ll a, ll b){
    return a>b;
}

void solve(){
    ll no_days, wb, bb, total_buttons;
    cin>>no_days>>wb>>bb;
    total_buttons = wb+bb;
    ll planned[no_days], completed[no_days],buttons[total_buttons], diff[no_days];

    for(ll i=0; i<no_days; i++) cin>>planned[i];
    for(ll i=0; i<no_days; i++) cin>>completed[i];

    for(ll i=0; i<total_buttons; i++) cin>>buttons[i];

    ll ans = 0;
    for(ll i=0; i<no_days; i++){
        diff[i] = planned[i]-completed[i];
        ans += diff[i];
    }

    sort(diff, diff+no_days, comp);
    sort(buttons, buttons+total_buttons, comp);
    
    for(ll i=0, j=0; i<total_buttons && j<no_days; i++){
        if(diff[j]>=buttons[i]){
            ans -= buttons[i];
            j++;
        }
    }
    cout<<ans<<endl;   
}

int main(){
    fstIO;
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}