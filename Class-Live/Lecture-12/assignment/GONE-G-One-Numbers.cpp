#include<iostream>
#include<vector>
#include<set>
#include<cstring>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);

set<int> s;
int mark[101];

void foo()
{
    for(int i=2;i*i<=100;i++)
    {
        if(mark[i]==0)
        {
            for(int j=i*2;j<=100;j+=i)
                mark[j]=1;
        }
    }
    for(int i=2;i<=100;i++)
        if(mark[i]==0)
            s.insert(i);
}

ll dp[10][70][2];
string a;

ll solve(int pos, int tight, int sum){
    if(pos == a.length()) return (s.find(sum)!=s.end());;

    if(dp[pos][sum][tight] != -1) return dp[pos][sum][tight];

    ll ans=0;
    int end=((tight)?(a[pos]-'0'):9);
    for(int i=0; i<=end; i++){
        ans += solve(pos+1, tight&(i==end), sum+i);
    }
    return dp[pos][sum][tight]=ans;
}

int main(){
    int t;
    cin>>t;
    foo();
    while(t--){
        ll p,q;
        cin>>p>>q;
        a = to_string(q);
        memset(dp, -1, sizeof(dp));
        ll ans = solve(0,1,0);

        if(p>0){
            p--;
            a = to_string(p);
            memset(dp, -1, sizeof(dp));
            ans -= solve(0,1,0);
        }
        cout<<ans<<endl;
    }
    return 0;
}