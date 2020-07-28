// https://codeforces.com/contest/1375/problem/C
#include<iostream>
#include<vector>
#include<stack>
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
    vector<int>arr(n);
    ip(arr, n);

    stack<int>s;
    for(int i=0; i<n; i++){
        if(s.empty()){
            s.push(arr[i]);
            continue;
        }
        while(!s.empty() and s.size()>1 and s.top()<arr[i]){
            s.pop();
        }
        if(s.top()>arr[i]){
            s.push(arr[i]);
        }
    }
    if(s.size()==1){
        cout<<"YES\n";
    }
    else cout<<"NO\n";
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