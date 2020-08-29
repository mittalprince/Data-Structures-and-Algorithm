// https://codeforces.com/contest/1131/problem/B
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
    int n;
    cin>>n;
    vector<pair<int,int> >arr(n);
    for(int i=0; i<n; i++){
        cin>>arr[i].first>>arr[i].second;
    }
    pair<int, int>prev = {0,0};
    int ans=1;
    for(pair<int, int>i:arr){
        if(max(prev.first, prev.second) <= min(i.first, i.second)){
            ans += min(i.first, i.second)-max(prev.first, prev.second);
            // {3,1}->{4,5} -> then using above line we include {4,4}, but there is also another {3,3}, so toh handle this we check below condition
            if(prev.first != prev.second)ans++;
        }
        prev=i;
    }
    cout<<ans<<endl;
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