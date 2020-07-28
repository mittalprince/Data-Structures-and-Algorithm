#include<iostream>
#include<vector>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=1; i<=n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define MAX 100005

int main(){
    int n;
    cin>>n;
    int height[n+1];
    ip(height, n);
    
    ll dp[MAX]={0};
    
    for(int i=2; i<=n; i++){
        dp[i] = dp[i-1]+abs(height[i]-height[i-1]);
        if(i>2) dp[i] = min(dp[i], dp[i-2]+abs(height[i]-height[i-2]));
    }
    cout<<dp[n]<<endl;
    return 0;
}