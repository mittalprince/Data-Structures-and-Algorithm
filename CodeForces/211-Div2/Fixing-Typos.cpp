// https://codeforces.com/contest/363/problem/C
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

int main(){

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    string s;
    cin>>s;
    string ans="";
    for(int i=0; i<s.length(); i++){
        int n=ans.length();
        if(n>=3 and (s[i]==ans[n-1]) and (ans[n-2] == ans[n-3]))continue;
        if(n>=2 and (s[i]==ans[n-1]) and (ans[n-2] == s[i]))continue;
        ans += s[i];
    }
    cout<<ans<<endl;
    return 0;
}