#include<iostream>
#include<vector>
#include <map>
#include <algorithm>
#include <climits>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);

map<pair<ll,ll>, ll>dp;
map<ll,ll> freq;
ll n;
vector<ll>arr;

/*
we have two options either we can include given arr[i] into sum or not;
1. if include then all no arr[i]-1, arr[i]+1 will be del (for this I make their freq to 0) and
   now as i have del all arr[i]-1, arr[i]+1, so whenever arr[i] occur we don't have arr[i]+1/arr[i]-1
   elements in arr and arr[i] will add into ans, so for this i just add arr[i]*freq[arr[i]] and call on f(i+1)

2. if current element no included in ans, so normally call on next element f(i+1)
*/
ll solve(ll i){
    if(i==n) return 0;

    if(dp.find({arr[i], freq[arr[i]]}) != dp.end()) return dp[{arr[i], freq[arr[i]]}];

    ll prev_no_freq = freq[arr[i]-1];
    ll next_no_freq = freq[arr[i]+1];
    freq[arr[i]-1]=0; // del arr[i]-1
    freq[arr[i]+1]=0; // del arr[i]+1 no

    ll opt1 = (arr[i]*freq[arr[i]])+solve(i+1); // when we decide 
    freq[arr[i]-1] = prev_no_freq; // backtracking
    freq[arr[i]+1] = next_no_freq; // backtracking

    ll opt2 = solve(i+1);

    dp[{arr[i], freq[arr[i]]}] = max(opt1, opt2);
    return dp[{arr[i], freq[arr[i]]}];
}

void Interative(){
    ll N, temp;
    cin>>N;
    ll arr[100005]={0}, dp[100005]={0};
    for(int i=0; i<N; i++){
        cin>>temp;
        arr[temp]++;
    }
    dp[0]=0; 
    dp[1]=arr[1]; // max ans when we have 1 present in arr is count of 1

    for(int i=2; i<100005; i++){
        // we have two option, consider ith item or not
        // if yes, then dp[i] = dp[i-2]+count(i)*i
        // else dp[i] = dp[i-1]
        // select max of these two
        dp[i] = max(dp[i-2]+arr[i]*i, dp[i-1]);
    }
    cout<<dp[100004]<<endl;
}

void Recursive(){
    cin>>n;
    for(int i=0; i<n; i++){
        ll temp;
        cin>>temp;
        freq[temp]++;
    }
    n=0;
    // sort arr no and make arr unique (i.e every element appear once in arr in sorted order)
    for(auto it: freq){
        arr.push_back(it.first);
        n++;
    }

    cout<<solve(0)<<endl;
}
int main(){
    // Interative();
    Recursive();
    return 0;
}