// https://codeforces.com/contest/861/problem/D
#include<iostream>
#include<vector>
#include<map>
#include<set>
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
    map<string, ll> m;
    vector<string> arr(n);

    for(int i=0; i<n; i++){
        cin>>arr[i];
        set<string>ss;
        for(int j=0; j<9; j++){
            string key="";
            for(int k=j; k<9; k++){
                key += arr[i][k];
                ss.insert(key);
            }
        }

        for(auto it:ss)m[it]++;
    }

    vector<string>ans(n, "");
    for(int i=0; i<n; i++){
        ans[i] = arr[i];
        for(int j=0; j<9; j++){
            string key="";
            for(int k=j; k<9; k++){
                key += arr[i][k];
                if(m[key]==1){
                    if(ans[i].length()>key.length()){
                        ans[i]=key;
                    }
                }
            }
        }
    }

    for(string i: ans){
        cout<<i<<endl;
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