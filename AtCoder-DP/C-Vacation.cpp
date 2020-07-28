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

ll n;
ll a[MAX],b[MAX],c[MAX];

void bottomUP(){
    ll dp[n][3];
    dp[0][0] = a[0], dp[0][1]=b[0], dp[0][2]=c[0];

    for(int i=1; i<n; i++){
        // if ith day I perform a activity, then what's the max points I have got on (i-1)th day,
        // by not performing a activity
        dp[i][0] = a[i] + max(dp[i-1][1], dp[i-1][2]);
        dp[i][1] = b[i] + max(dp[i-1][0], dp[i-1][2]); 
        dp[i][2] = c[i] + max(dp[i-1][0], dp[i-1][1]); 
        // cout<<dp[i][0]<<" "<<dp[i][1]<<" "<<dp[i][2]<<endl;
    }
 
    cout<<max(dp[n-1][0], max(dp[n-1][1], dp[n-1][2]))<<endl;
}

int main(){
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>a[i]>>b[i]>>c[i];
    }
    bottomUP();
    return 0;
}