// https://www.hackerearth.com/practice/algorithms/string-algorithm/basics-of-string-manipulation/practice-problems/algorithm/largest-string-29/description/
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
    int n,m;
    cin>>n>>m;

    string s;
    cin>>s;

    vector<int>t(n, n);
    stack<int>S;

    for(int i=n-1; i>=0; i--){
        while(!S.empty() and s[i]>=s[S.top()])S.pop();
        if(!S.empty())t[i] = S.top();
        S.push(i);
    }

    string ans="";
    for(int i=0; i<n;){
        if(t[i]-i<=m){
            m -= (t[i]-i);
            i = t[i];
        }
        else{
            ans += s[i++];
        }
    }
    cout<<ans<<endl;
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