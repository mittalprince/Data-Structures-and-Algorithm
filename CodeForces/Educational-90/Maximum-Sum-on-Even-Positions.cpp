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

ll kadanes(vector<int>arr){
    ll curr_sum=0, max_sum=0;
    for(int i=0; i<arr.size(); i++){
        curr_sum += arr[i];
        if(curr_sum>max_sum){
            max_sum=curr_sum;
        }
        if(curr_sum<0){
            curr_sum=0;
        }
    }
    return max_sum;
}

void solve(){
    int n;
    cin>>n;
    vector<int>arr(n);
    ll ans=0;
    for(int i=0; i<n; i++){
        cin>>arr[i];
        if((i%2)==0) ans += arr[i];
    }

    
    vector<int>diff;
    for(int i=1; i<n; i+=2){
        diff.push_back(arr[i]-arr[i-1]);
    }
    ll t=kadanes(diff);
    diff.clear();
    for(int i=2; i<n; i+=2){
        diff.push_back(arr[i-1]-arr[i]);
    }
    t = max(t, kadanes(diff));
    ans += t;
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