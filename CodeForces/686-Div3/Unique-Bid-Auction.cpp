//https://codeforces.com/contest/1454/problem/B
#include<iostream>
#include<vector>
#include<map>
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
    ip(arr, n);

    map<int, int>m, freq;
    for(int i=0; i<n; i++){
        freq[arr[i]]++;
        if(m.count(arr[i])==0){
            m[arr[i]]=i+1;
        }
    }

    for(auto it: m){
        if(freq[it.first]==1){
            cout<<it.second<<endl;
            return;
        }
    }
    cout<<"-1\n";
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