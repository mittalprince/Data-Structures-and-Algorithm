// https://codeforces.com/contest/404/problem/A
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
    vector<string>arr(n);
    char dia, antidia;
    int unique=1;

    bool flag=true;
    for(int i=0; i<n; i++){
        cin>>arr[i];
        if(i==0){
            dia=arr[i][0];
            antidia=arr[i][1];
            if(dia != antidia) unique++;
        }
        for(int j=0; j<arr[i].size(); j++){
            if(i+j == (n-1) or i==j){
                flag &= (arr[i][j]==dia);
            }
            else{
                flag &= (arr[i][j]==antidia);
            }
            if(!flag)break;
        }
    }

    if(flag and unique==2){
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