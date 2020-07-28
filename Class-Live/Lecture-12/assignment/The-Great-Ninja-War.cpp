#include<iostream>
#include<vector>
#include<cstring>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define LCM 2520

ll dp[15][2520][515];
// state -> pos, sum, mask(as 1-9 total 9 digit, 2^9)
string s;

ll pow(ll a, ll b){
    ll ans=1;
    while(b>0){
        if(b&1){
            ans = (ans*a)%LCM;
        }
        a = (a*a)%LCM;
        b = b/2;
    }
    return ans;
}

/* 
Logic:
here we use four dp state pos, tight, sum, mask

mask -> represent which digit I have included in my number. It is a 9 bit where ith bit define whether the numer include (i+1)digit or not
means say 100010001 -> I have include 9,5,1 digit in my number

2. Why we take LCM: LCM should be such that with the help of this we can get the modulo with each and every digit. 
Hence this value should be VALUE=LCM(1,2,3,4,5,6,7,8,9)=2520.

3. at each step which digit we have taken we find i^i and add this into sum

4. at last (when pos == s.length()) we check whether we take ith bit or not, if yes whether it divides sum or not
*/
ll solve(int pos, bool tight, int sum, int mask){
    if(pos == s.length()){
        for(int i=0; i<9; i++){
            if((mask&(1<<i)) && sum%(i+1) != 0){
                return 0;
            }
        }
        return 1;
    }

    if(!tight && dp[pos][sum][mask] != -1) return dp[pos][sum][mask];

    ll ans=0;
    int end = ((tight)?(s[pos]-'0'):9);
    for(int i=0; i<=end; i++){
        ll new_val = (i==0)?0:pow(i,i);
        ll new_mask = (i==0)?mask: (mask | (1<<(i-1)));
        ans += solve(pos+1, tight&&(i==end), (sum+new_val)%LCM, new_mask);
    }

    if(!tight){
        dp[pos][sum][mask] = ans;
    }
    return ans;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        ll a,b;
        cin>>a>>b;
        a--;

        memset(dp, -1, sizeof(dp));
        s = to_string(b);
        ll ans = solve(0,1,0,0);

        memset(dp, -1, sizeof(dp));
        s = to_string(a);

        ans -= solve(0,1,0,0);
        cout<<ans<<endl;
    }
    return 0;
}