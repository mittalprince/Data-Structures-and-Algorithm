// https://hack.codingblocks.com/app/contests/1496/258/problem
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

string s;
int ans=0;

int solve(int i){
    if(s[i+2]=='\0')return ans;

    if(s[i] == s[i+2] and s[i]!=s[i+1]){
        ans++;
    }
    return solve(i+1);
}
int main(){

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    cin>>s;
    cout<<solve(0)<<endl;
    
    return 0;
}