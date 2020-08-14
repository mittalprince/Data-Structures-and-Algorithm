// https://codeforces.com/contest/1315/problem/C
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
    int arr[n];
    
    bool freq[205]={0};
    for(int i=0; i<n; i++){
        cin>>arr[i];
        freq[arr[i]]=true;
    }

    vector<int>ans;
    for(int i=0;i<n; i++){
        ans.push_back(arr[i]);
        ll val = arr[i];
        while(freq[val] and val<(2*n))val++;
        if(freq[val])break;
        freq[val]=true;
        ans.push_back(val);
    }

    if(ans.size()<2*n){
        cout<<"-1\n";
        return;
    }
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

    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}