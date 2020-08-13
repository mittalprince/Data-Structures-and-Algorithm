// https://atcoder.jp/contests/arc087/tasks/arc087_a
#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<cmath>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);

void solve(){
    int n,temp;
    cin>>n;
    map<ll ,ll>m;
    for(int i=0; i<n; i++){
        cin>>temp;
        m[temp]++;
    }
    ll ans=0;
    for(auto it: m){
        if(it.first < it.second){
            ans += (it.second-it.first);
        }
        else if(it.first > it.second){
            ans += it.second;
        }
    }
    cout<<ans<<endl;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}