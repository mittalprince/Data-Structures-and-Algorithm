// https://codeforces.com/contest/899/problem/C
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

void solve(){
    ll n;
    cin>>n;
    ll sum = n*(n+1)/2;
    cout<<(sum&1)<<endl;
    sum -= (sum/2);
    ll last=n;
    vector<int>ans;

    while(sum>0){
        if(sum<last){
            ans.push_back(sum);
            break;
        }
        ans.push_back(last);
        sum -= last;
        last--;
    }

    cout<<ans.size()<<" ";
    for(int i: ans){
        cout<<i<<" ";
    }
    cout<<endl;
}

int main(){

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    int t=1;
    // cin>>t;
    while(t--){
        solve();
    }
    return 0;
}