// https://codeforces.com/contest/1385/problem/D
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

int minCost(string s, char c){
    if(s.empty())return 0;

    if(s.length()==1){
        return s[0]!=c;
    }

    int n=s.length();
    int opt1=0, opt2=0;
    for(int i=0; i<(n/2); i++){
        if(s[i]!=c)opt1++;
    }
    for(int i=(n/2); i<n; i++){
        if(s[i]!=c)opt2++;
    }

    // we have option
    // 1. make first half c-good string and second half c+1 good string
    // 2. make second half c-good.string and first half c+1 good string
    opt1 += minCost(s.substr(n/2, n/2), c+1);
    opt2 += minCost(s.substr(0, n/2), c+1);

    return min(opt1, opt2);
}

void solve(){
    int n;
    cin>>n;
    string s;
    cin>>s;

    cout<<minCost(s, 'a')<<endl;
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