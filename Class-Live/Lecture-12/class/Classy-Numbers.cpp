#include<iostream>
#include<vector>
#include<cstring>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);

ll dp[20][4][2];
ll l, r;
string s;

ll solve(int pos, int ct, int tight){
    if(pos == s.length()) return 1;
    
    if(dp[pos][ct][tight] != -1) return dp[pos][ct][tight];

    ll ans=0;
    int end = ((tight)?(s[pos]-'0'):9);
    for(int i=0; i<=end; i++){
        ll updated_ct = ct + (i>0);
        if(updated_ct<=3){
            ans += solve(pos+1, updated_ct, tight&(i==end));
        }
    }
    dp[pos][ct][tight]=ans;
    return dp[pos][ct][tight];
}

int main(){
    int t;
    cin>>t;
    while(t--){
        cin>>l>>r;
        s = to_string(r);
        memset(dp, -1, sizeof(dp));
        ll ans = solve(0, 0, 1);

        l--;
        s = to_string(l);
        memset(dp, -1, sizeof(dp));
        ans -= solve(0, 0, 1);
        cout<<ans<<endl;
    }
    return 0;
}