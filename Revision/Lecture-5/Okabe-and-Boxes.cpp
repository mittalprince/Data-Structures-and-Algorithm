// https://codeforces.com/contest/821/problem/C
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
    vector<int>arr;
    int ct=1, ans=0;

    for(int i=0; i<2*n; i++){
        string op;
        cin>>op;
        if(op=="remove"){
            if(!arr.empty()){
                if(arr.back()==ct)arr.pop_back();
                else{
                    arr.clear();
                    ans++;
                }
            }
            ct++;
        }
        else{
            int x;
            cin>>x;
            arr.push_back(x);
        }
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