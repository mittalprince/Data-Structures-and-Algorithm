#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);

ll countBits(ll n){
    ll ct=0;
    while(n>0){
        n>>=1;
        ct++;
    }
    return ct;
}
int main(){
    ll n;
    cin>>n;
    
    ll ans=0;
    vector<ll>powers;

    while(((n+1)&n) != 0){
        ll ct = countBits(n);
        ll val = (1<<(ct))-1;
        n ^=val;
        powers.push_back(ct);
        ans++;
        if(((n+1)&n) == 0) break;

        n += 1;
        ans++;
    }
    cout<<ans<<endl;
    for(ll i: powers){
        cout<<i<<" ";
    }
    cout<<endl;
    return 0;
}