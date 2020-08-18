// https://www.codechef.com/problems/CHEFMATH
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
#define endl "\n"
#define MAX 43

ll arr[50]={0};


ll totalWays(ll x, ll k, ll i){
    if(x==0 and k==0)return 1;
    if(x==0||k==0||i<0) return 0;

    ll ct = totalWays(x,k,i-1);
    if(x>=arr[i] and x<= k*arr[i]){
        ct += totalWays(x-arr[i], k-1, i);
    }
    return ct;
}

int main(){

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    fstIO;
    
    arr[0]=1;
    arr[1]=2;
    for(int i=2; i<MAX; i++){
        arr[i] = arr[i-1]+arr[i-2];
    }

    int q;
    cin>>q;
    while(q--){
        ll x,k;
        cin>>x>>k;
        ll ct = totalWays(x, k, MAX-1);
        cout<<(ct%MOD)<<endl;
    }
    return 0;
}