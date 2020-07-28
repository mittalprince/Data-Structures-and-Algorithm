#include<iostream>
#include<vector>
#include<cstring>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);

ll cal(ll a){
    if(a<10) return a;
    ll ans=a/10+9;
    int lsb = a%10;
    while(a>=10) a/=10;
    if(lsb<a) ans--;
    return ans;
}

void mathsApproach(){
    ll a,b;
    cin>>a>>b;
    cout<<cal(b)-cal(a-1)<<endl;
}

ll dp[20][10][10][2][2];
string s;

ll solve(int pos, int first, int last, bool tight, bool start){
    if(pos == s.length()) return first == last;

    if(dp[pos][first][last][tight][start] != -1) return dp[pos][first][last][tight][start];

    ll ans=0;
    int end = ((tight)?(s[pos]-'0'):9);
    if(start == 0){
        ans += solve(pos+1, first, last, tight&&(s[pos] == '0'), 0);
        for(int i=1; i<=end; i++){
            ans += solve(pos+1, i, i, tight&&(i==end), 1);
        }
    }
    else{
        for(int i=0; i<=end; i++){
            ans += solve(pos+1, first, i, tight&&(i==end), start);
        }
    }
    return dp[pos][first][last][tight][start] = ans;
}

int main(){
    ll a,b;
    cin>>a>>b;
    s = to_string(b);
    memset(dp, -1, sizeof(dp));
    ll ans = solve(0,0,0,1,0);

    a--;

    s = to_string(a);
    memset(dp, -1, sizeof(dp));
    ans -= solve(0,0,0,1,0);
    cout<<ans<<endl;
    return 0;
}
