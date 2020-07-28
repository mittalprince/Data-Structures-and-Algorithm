#include<iostream>
#include<vector>
#include<bitset>
using namespace std;
typedef unsigned long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);

int main(){
    ll x,d;
    cin>>x>>d;
    bitset<60>X(x);

    vector<ll>ans;
    ll prev=1;
    for(int i=60; i>=0; i--){
        if(X[i]){
            for(int j=0; j<i; j++){
                ans.push_back(prev);
            }
            prev += d;
            ans.push_back(prev);
            prev += d;
        }
    }

    cout<<ans.size()<<endl;
    for(ll i: ans){
        cout<<i<<" ";
    }
    cout<<endl;
    return 0;
}