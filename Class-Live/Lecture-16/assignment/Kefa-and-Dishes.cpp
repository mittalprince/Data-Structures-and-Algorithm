#include<iostream>
#include<vector>
#include<cstring>
#include<map>
#include<cassert>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=1; i<=n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);

ll dp[20][(1<<18)+1];
//state -> pos, mask;
// pos -> pos of prev dish, used to find extra_satisfaction
// mask -> indicate which dishes I have eat already
ll n,m,k;
ll arr[20]={0};
map<pair<int, int>, int>extra_satisfaction;

ll solve(int prev_dish, ll mask){
    if(__builtin_popcount(mask) == m){// we have eaten m dishes
        return 0;
    }

    if(dp[prev_dish][mask] != -1) return dp[prev_dish][mask];

    ll ans=0;
    for(int i=1; i<=n; i++){// consider all combination,
    // eat ith dish and check what is max satisfaction after updating mask
        if(((1<<i)&mask)==0){// check the ith dish has not eat before anytime
            ll opt1 = arr[i]; // take curr dish satisfaction
            if(extra_satisfaction.find({prev_dish, i}) != extra_satisfaction.end()){
                opt1 += extra_satisfaction[{prev_dish, i}];// chek whehter we have just finished the x dish defore y or not
            }
            opt1 += solve(i, mask|(1<<i)); // now prev_dish will be i and add current dish into mask
            ans = max(ans, opt1);
        }
    }
    return dp[prev_dish][mask] = ans;
}

int main(){
    cin>>n>>m>>k;
    ip(arr, n);

    for(int i=0; i<k; i++){
        int x,y,cost;
        cin>>x>>y>>cost;
        extra_satisfaction[{x,y}]=cost;
    }

    memset(dp, -1, sizeof(dp));
    cout<<solve(0, 0)<<endl;
    return 0;
}