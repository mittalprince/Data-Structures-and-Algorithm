#include<iostream>
#include<vector>
#include<cstring>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define MOD 1000000007
#define MAX 100005

ll n;
ll arr[MAX], dp[MAX][4][(1<<4)], masks[MAX];

void setMasks(){
    for(int i=0; i<n; i++){
        ll x = arr[i];
        ll mask=0;
        while(x){
            int val = x%10;
            if(val == 2) mask |= (1<<0);
            else if(val==3) mask |= (1<<1);
            else if(val==5) mask |= (1<<2);
            else if(val==7) mask |= (1<<3);
            x /= 10;
        }
        masks[i] = mask;
    }
}

ll solve(ll pos, ll no_taken, ll mask){
    if(pos == n){
        return (no_taken == 3 && mask);
    }

    ll &res = dp[pos][no_taken][mask];
    
    if(res != -1) return res;

    ll opt1 = solve(pos+1, no_taken, mask);
    ll opt2 = 0;
    if(no_taken<=2) opt2 = solve(pos+1, no_taken+1, mask & masks[pos]);

    return res = opt1+opt2;
}

int main(){

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    cin>>n;
    ip(arr, n);
    
    setMasks();
    memset(dp, -1, sizeof(dp));
    cout<<solve(0 ,0 , (1<<4)-1)<<endl;
    return 0;
}