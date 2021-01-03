//https://leetcode.com/problems/beautiful-arrangement/
#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define ip1(arr, n) for(int i=1; i<=n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define debug(x) cout<<x<<"\n";
#define inf 1e9
#define INF 1e16
#define MOD 1000000007

int dp[(1<<17)];

int solve(int pos, int bit, int n){
    if(pos == n){
        return 1;
    }    
    if(dp[bit] != -1)return dp[bit];

    int ans=0;
    for(int i=1; i<=n; i++){
        if(!(bit&(1<<i))){
            if((pos+1)%i==0 or (i%(pos+1))==0){
                ans += solve(pos+1, bit|(1<<i), n);
            }
        }
    }
    return dp[bit]=ans;
}

int countArrangement(int N) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    memset(dp, -1, sizeof(dp)); 
    return solve(0, 0, N);
}

int main(){

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    int n;
    cin>>n;
    vector<int> arr(n);
    
    return 0;
}