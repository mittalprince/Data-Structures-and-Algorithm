#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define debug(x) cout<<x<<"\n";
#define inf 1e9
#define INF 1e16
#define MOD 1000000007

void solve(){
    ll n;
    cin>>n;

    ll arr[n];
    ip(arr, n);
    vector<bool>ans(n, true);

    for(int i=1; i<n-1; i++){
        int diff=1;
        while((abs(arr[i-diff]-arr[i])+abs(arr[i]-arr[i+1])) == abs(arr[i-diff]-arr[i+1])){
            diff++;
            ans[i]=false;
            i++;
            if(i==n-1)break;
        }
    }

    int ct=0;
    for(int i=0; i<n; i++){
        ct += ans[i];
    }
    cout<<ct<<endl;
    for(int i=0; i<n; i++){
        if(ans[i])cout<<arr[i]<<" ";
    }
    cout<<endl;
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