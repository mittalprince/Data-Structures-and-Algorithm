#include<iostream>
#include<vector>
#include<cstring>
using namespace std;
typedef int ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define mod 1000000007

ll n, dp[80][(1ll<<20)+1];
//state -> pos, mask
// mask -> denote ki which numbers i can form using segments
// pos -> iss pos par segment start kiya hai new
string s;

ll solve(int pos, ll mask){
    if(dp[pos][mask] != -1) return dp[pos][mask];
    
    ll ans=0;
    if(mask>0){
        if(__builtin_popcount(mask+1) == 1){// check whether we have 1 to m numbers formed
            ans++;
        }
    }   
    int decimalNo=0;
    for(int i=pos; i<n; i++){// assume we already have a segment before this pos
        decimalNo *= 2;
        decimalNo += (s[i]-'0');

        if(decimalNo==0)continue;
        if(decimalNo>20) break;

        ans = (ans + solve(i+1, mask|(1<<(decimalNo-1))))%mod;
    }

    return dp[pos][mask] = (ans%mod);
}

int main(){
    cin>>n;
    cin>>s;

    ll ans=0;
    memset(dp, -1, sizeof(dp));
    for(int i=0; i<n; i++){// insert segment at each possible index
        ans = (ans + solve(i, 0))%mod;
    }
    cout<<ans<<endl;
    return 0;
}