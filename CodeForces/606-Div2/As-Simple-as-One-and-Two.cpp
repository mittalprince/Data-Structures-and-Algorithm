// https://codeforces.com/contest/1277/problem/C
    #include<iostream>
#include<vector>
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
    int idx = s.find("twone");
    vector<int>ans;

    while(idx != string::npos){
        ans.push_back(idx+3);
        s[idx+2]='?';
        idx = s.find("twone", idx+1);
    }

    idx = s.find("one");
    while(idx != string::npos){
        ans.push_back(idx+2);
        s[idx+1]='?';
        idx = s.find("one", idx+1);
    }

    idx = s.find("two");
    while(idx != string::npos){
        ans.push_back(idx+2);
        s[idx+1]='?';
        idx = s.find("two", idx+1);
    }

    cout<<ans.size()<<endl;
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