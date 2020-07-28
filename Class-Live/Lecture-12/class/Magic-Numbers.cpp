#include<iostream>
#include<vector>
#include<cstring>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define mod 1000000007

ll dp[2005][2005][2][2][2];
string a,b,s;
ll m,d;

ll solve(int pos, ll mo, bool tight, bool even, bool start){
    if(pos == s.length()) return mo==0;

    if(dp[pos][mo][tight][even][start] != -1) return dp[pos][mo][tight][even][start];

    ll ans=0;
    int end = ((tight)?(s[pos]-'0'):9);

    if(start == 0){
        ans = (ans+solve(pos+1, mo, tight&(s[pos]=='0'), 0, start))%mod;
        for(int i=1; i<=end; i++){
            if(i != d){
                ans = (ans+solve(pos+1, (mo*10+i)%m, tight&(i==end), 1, 1))%mod;
            }
        }
    }
    else{
        for(int i=0; i<=end; i++){
            if(even && (i==d)){
                ans = (ans+solve(pos+1, (mo*10+i)%m, tight&(i==end), !even, 1))%mod;
            }
            else if(!even && (i != d)){
                ans = (ans+solve(pos+1, (mo*10+i)%m, tight&(i==end), !even, 1))%mod;
            }
        }
    }
    dp[pos][mo][tight][even][start] = ans;
    return dp[pos][mo][tight][even][start];
}

int main(){
    cin>>m>>d;
    cin>>a>>b;
    memset(dp, -1, sizeof(dp));

    s=b;
    ll ans = solve(0, 0, 1, 0, 0)%mod;

    s = a;
    memset(dp, -1, sizeof(dp));
    ans = (ans - solve(0, 0, 1, 0, 0)+mod)%mod;

    ll mo=0;
    bool flag=true;
    for(int i=0; i<a.length(); i++){
        if(i%2 && ((a[i]-'0')!=d)){
            flag=false;
            break;
        }
        else if(i%2==0 && ((a[i]-'0') == d)){
            flag=false;
            break;
        }
        mo = (mo*10+(a[i]-'0'))%m;
    }

    if(flag && !mo){
        ans = (ans+1)%mod;
    }
    cout<<ans<<endl;
    return 0;
}