#include<iostream>
#include<vector>
#include<algorithm>
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

void solve(){
    int n,k;
    cin>>n>>k;
    vector<ll>arr(n);
    ip(arr, n);
    sort(arr.begin(), arr.end());
    vector<ll>brr;
    ll ans=0;
    
    for(int i=0; i<k; i++){
        int x;
        cin>>x;
        if(x==1){
            ans += 2*arr.back();
            arr.pop_back();
        }
        else{
            brr.push_back(x);
        }
    }
    sort(brr.begin(), brr.end(), greater<ll>());
    int i=0, j=arr.size()-1;
    
    for(int p=0; p<brr.size(); p++){
        ans += arr[i]+arr[j];
        i += (brr[p]-1);
        j--;
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