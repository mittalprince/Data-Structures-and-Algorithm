//https://codeforces.com/contest/1454/problem/C
#include<iostream>
#include<vector>
#include<climits>
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
#define MAX 1000000

ll arr[MAX], temp[MAX], mapone[MAX], maptwo[MAX];

void solve(){
    ll n;
    cin>>n;
    arr[0]=-1;

    for(ll i=1; i<=n; i++){
        mapone[i]=-1,maptwo[i]=-1;
    }

    for(ll i=1; i<=n; i++){
        cin>>arr[i];
        if (arr[i]!=arr[i-1]){
            temp[arr[i]]++;
            if (mapone[arr[i]]==-1) mapone[arr[i]]=i;
        }
        maptwo[arr[i]]=i;
    }

    ll ans=LLONG_MAX;

    for (ll i=1;i<=n;i++){
        if (temp[i]!=0){
            ans=min(ans,temp[i]-1+(mapone[i]!=1)+(maptwo[i]!=n));
            temp[i]=0;
        }
    }
    cout<<ans<<endl;
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