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
#define MAX 100005

void solve(){
    int n;
    cin>>n;

    ll arr[n+1];
    ll freq[MAX]={0};
    freq[0]=1;

    for(ll i=0; i<n; i++){
        cin>>arr[i];
        if(i>0) arr[i] = arr[i] + arr[i-1];
        arr[i] %= n;
        arr[i] = (arr[i]+n)%n;
        freq[arr[i]]++;
    }

    ll ans=0;
    for(ll i=0; i<n; i++){
        ans += (freq[i]*(freq[i]-1))/2;
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