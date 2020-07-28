#include<iostream>
#include<vector>
#include<cstring>
#include<cmath>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define MAX 100005
#define Inf 1000000000005

int main(){
    int n,k;
    cin>>n>>k;
    ll height[n];
    ip(height, n);
    
    ll dp[MAX];
    for(int i=0; i<n+5; i++) dp[i]=Inf;
    dp[0]=0;

    for(int i=0; i<n; i++){
        for(int j=1; j<=k && (i+j)<n; j++){
            dp[i+j] = min(dp[i+j], dp[i]+abs(height[i]-height[i+j]));
        }
    }
    cout<<dp[n-1]<<endl;
    return 0;
}