// https://codeforces.com/contest/118/problem/B
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

    for(int i=n; i>=0; i--){
        for(int j=0; j<2*i; j++)cout<<" ";
        vector<int>a;
        for(int j=0; j<=n-i; j++)a.push_back(j);
        int e=a.size()-2;
        while(e>=0){
            a.push_back(a[e--]);
        }
        for(int k=0; k<a.size(); k++){
            cout<<a[k];
            if(k!=a.size()-1)cout<<" ";
        }
        cout<<endl;
    }
    for(int i=1; i<=n; i++){
        for(int j=0; j<2*i; j++)cout<<" ";
        vector<int>a;
        for(int j=0; j<=n-i; j++)a.push_back(j);
        int e=a.size()-2;
        while(e>=0){
            a.push_back(a[e--]);
        }
        for(int k=0; k<a.size(); k++){
            cout<<a[k];
            if(k!=a.size()-1)cout<<" ";
        }
        cout<<endl;
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