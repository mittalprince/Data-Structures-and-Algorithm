#include<iostream>
#include<vector>
#include<cstring>
#include<climits>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define MAX 100005
#define Inf 1000000000005

ll n,k;
ll arr[MAX], dp[MAX]={0};

void bottomUp(){
    dp[0]=0;
    for(int i=0; i<n; i++){
        for(int j=1; j<=k; j++){
            if(i+j<n) dp[i+j] = min(dp[i+j], dp[i]+abs(arr[i]-arr[i+j]));
        }
    }
    cout<<dp[n-1]<<endl;
}

ll solve(ll pos){
    if(pos >= n-1) return 0;

    if(dp[pos]!=-1){return dp[pos];}

	ll ans=INT_MAX;

	for(int j=1; j<=k&& pos+j<n; j++){
		ans = min(ans, abs(arr[pos]-arr[pos+j]) + solve(pos+j));
	}

	dp[pos]=ans;
	return dp[pos];
}

void topDown(){
    memset(dp, -1, sizeof(dp));
    cout<<solve(0)<<endl;
}

int main(){
    cin>>n>>k;
    ip(arr, n);
    // for(int i=0; i<n+5; i++) dp[i]=Inf;
    // bottomUp();
    topDown();
    return 0;
}