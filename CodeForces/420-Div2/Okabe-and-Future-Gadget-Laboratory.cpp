// https://codeforces.com/contest/821/problem/A
#include<iostream>
#include<vector>
#include<unordered_map>
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
    vector<vector<int> >arr(n, vector<int>(n));

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>arr[i][j];
        }
    }

    bool flag=true;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(arr[i][j]!=1){
                bool exit=false;
                unordered_map<int, bool>col;
                for(int k=0; k<n; k++){
                    if(k!=j)col[arr[i][k]]=true;
                }
                for(int k=0; k<n; k++){
                    if(k != i and col[arr[i][j]-arr[k][j]]){
                        exit=true;
                        break;
                    }
                }
                if(!exit){
                    cout<<"No\n";
                    return;
                }
            }
        }
    }
    cout<<"Yes\n";
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