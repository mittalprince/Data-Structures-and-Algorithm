// https://codeforces.com/contest/1398/problem/B
#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
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
    string s;
    cin>>s;
    int n=s.length();
    vector<int>ans;

    for(int i=0; i<n;){
        if(s[i]=='1'){
            int ct=0;
            while(i<n and s[i]=='1'){
                ct++;
                i++;
            }
            ans.push_back(ct);
        }
        else i++;
    }
    sort(ans.rbegin(), ans.rend());
    ll res=0;
    for(int i=0; i<ans.size(); i+=2){
        res += ans[i];
    }
    cout<<res<<endl;

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