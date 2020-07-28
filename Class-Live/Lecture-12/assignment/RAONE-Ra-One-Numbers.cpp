#include<iostream>
#include<vector>
#include<cstring>
#include<map>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);

ll dp[10][50][50][2][2];
// state -> pos,even_sum,odd_sum,tight,start,even_pos
string s;

ll solve(int pos, int even_sum, int odd_sum, bool tight, bool start){

    if(pos == s.length()) {
        return ((even_sum - odd_sum) == 1);
    }

    if(dp[pos][even_sum][odd_sum][tight][start] != -1){
        return dp[pos][even_sum][odd_sum][tight][start];
    }

    ll ans=0;
    int end=((tight)?(s[pos]-'0'):9);
    if(start == 0){
        ans = solve(pos+1, even_sum, odd_sum, tight&&(s[pos] == '0'), 0);
        for(int i=1; i<=end; i++){
            if((s.length()-pos-1)&1){
                ans += solve(pos+1, even_sum+i, odd_sum, tight&&(i==end), 1);
            }
            else{
                ans += solve(pos+1, even_sum, odd_sum+i, tight&&(i==end), 1);
            }
        }
    }
    else{
        for(int i=0; i<=end; i++){
            if((s.length()-pos-1)&1){
                ans += solve(pos+1, even_sum+i, odd_sum, tight&&(i==end), 1);
            }
            else{
                ans += solve(pos+1, even_sum, odd_sum+i, tight&&(i==end), 1);
            }
        }
    }
    return dp[pos][even_sum][odd_sum][tight][start]=ans;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        ll a,b;
        cin>>a>>b;

        s = to_string(b);
        memset(dp, -1, sizeof(dp));
        ll ans = solve(0,0,0,1,0);

        if(a>0){
            a--;
            s = to_string(a);
            memset(dp, -1, sizeof(dp));
            ans -= solve(0,0,0,1,0);
        }
        cout<<ans<<endl;
    }

    return 0;
}