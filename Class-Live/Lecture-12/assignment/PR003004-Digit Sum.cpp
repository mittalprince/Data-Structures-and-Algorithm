// Link : https://www.spoj.com/problems/PR003004/
#include<iostream>
#include<vector>
#include<cstring>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);

ll dp[20][150][2];
string s;

ll solve(int pos, int tight, int sum){
    if(pos == s.length()) return sum;

    if(dp[pos][sum][tight] != -1) return dp[pos][sum][tight];

    ll ans=0;
    int end=((tight)?(s[pos]-'0'):9);
    for(int i=0; i<=end; i++){
        ans += solve(pos+1, tight&(i==end), sum+i);
    }
    return dp[pos][sum][tight]=ans;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        ll a, b;
        cin >> a >> b;

        memset(dp, -1, sizeof(dp));
        s = to_string(b);
        ll ans = solve(0,1, 0);

        if(a>0){
            a--;
            memset(dp, -1, sizeof(dp));
            s = to_string(a);
            ans -= solve(0, 1, 0);
        } 
        
        cout<<ans<<endl;
    }
    return 0;
}