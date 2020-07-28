#include<iostream>
#include<vector>
#include<cstring>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);

ll dp[12][100][100][2];
//state -> pos, num, sum, tight
string s;
ll l,r,val;

ll solve(int pos, int sum, int num, int tight){
    if(pos == s.length()){
        return (num%val ==0 && sum%val == 0);
    }

    if(dp[pos][sum][num][tight] != -1) return dp[pos][sum][num][tight];

    int end = ((tight)?(s[pos]-'0'): 9);
    ll ans=0;
    for(int i=0; i<=end; i++){
        ans += solve(pos+1, (sum+i)%val, (num*10+i)%val, tight&&(i==end));
    }

    return dp[pos][sum][num][tight]=ans;
}

int main(){
    int t, tc=1;
    cin>>t;
    while(t--){
        cin>>l>>r>>val;

        cout<<"Case "<<tc++<<": ";
        if(val>= 100){
            cout<<"0\n";
        }
        else{
            ll ans=0;
            memset(dp, -1, sizeof(dp));
            s = to_string(r);
            ans = solve(0, 0, 0, 1);

            memset(dp, -1, sizeof(dp));
            s = to_string(l);
            ans -= solve(0, 0, 0, 1);

            bool flag=true;
            ll sum=0, num=0;
            for(int i=0; i<s.length(); i++){
                sum += (s[i]-'0')%val;
                num = num*10+(s[i]-'0')%val;
            }

            if(sum%val == 0 && num%val == 0)ans++;  
            cout<<ans<<endl; 
        }
    }
    return 0;
}