// https://codeforces.com/contest/1380/problem/B
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
    string s;
    cin>>s;

    int r=0, si=0, p=0;
    for(char i: s){
        if(i=='R')r++;
        else if(i=='P')p++;
        else si++;
    }
    
    int ans = max(si, max(r, p));
    if(ans == r){
        string ans(s.length(), 'P');
        cout<<ans<<endl;
    }
    else if(ans == p){
        string ans(s.length(), 'S');
        cout<<ans<<endl;
    }
    else{
        string ans(s.length(), 'R');
        cout<<ans<<endl;
    }
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