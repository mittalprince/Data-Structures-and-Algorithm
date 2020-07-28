#include<iostream>
#include<vector>
#include<cstring>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);

ll dp[(1<<18)+1][100];
string s;
ll mod;

ll solve(ll mask, ll m){
    if(mask == ((1<<s.length())-1)){
        return m==0;
    }

    if(dp[mask][m] != -1) return dp[mask][m];

    // for the paricular ith pos I have consider ch[0..9] or not
    bool digitPlaceAtIthIndex[10]={0};
    ll ans=0;

    for(int i=0; i<s.length(); i++){
        if(mask==0 and s[i] == '0'){
            // prevent leading zeros
            continue;
        }
        // agr mein abhi tak ith pos par s[i]-'0' val place nahi kiya and
        // abhi tak mein iss pos ko consider nahi kiya, means ki pos par koi val place nahi ki ho
        if(!digitPlaceAtIthIndex[s[i]-'0'] and !(mask&(1<<i))){
            digitPlaceAtIthIndex[s[i]-'0']=true;
            ans += solve(mask|(1<<i), (m*10+(s[i]-'0'))%mod);
        }
    }

    return dp[mask][m]=ans;
}

int main(){
    int t;
    cin>>t;
     while(t--){
        memset(dp, -1, sizeof(dp));
        cin>>s;
        cin>>mod;
        cout<<solve(0, 0)<<endl;
    }
    return 0;
}