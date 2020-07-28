// https://codeforces.com/contest/1382/problem/C1
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
    string a,b;
    cin>>a>>b;

    vector<ll>ans;
    char curr=a[0];

    for(int i=0; i<n; i++){
        if(a[i] == curr)continue;
        else{
            ans.push_back(i);
            if(curr == '0')curr='1';
            else curr='0';
            // cout<<i<<" "<<curr<<endl;
        }
    }
    // for(int i: ans){
    //     cout<<i<<" ";
    // }
    // cout<<endl;
    for(int i=n-1; i>=0; i--){
        if(b[i] == curr)continue;
        else{
            ans.push_back(i+1);
            if(curr == '0')curr='1';
            else curr='0';
        }
    }

    cout<<ans.size()<<" ";
    if(ans.size()){
        for(int i: ans){
            cout<<i<<" ";
        }
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