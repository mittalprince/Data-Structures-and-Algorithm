#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);

int main(){
    int n;
    cin>>n;
    int a[n],b[n],c[n];
    
    for(int i=0; i<n; i++){
        cin>>a[i]>>b[i]>>c[i];
    }

    ll dp[n][3];
    // dp[i][j] -> what max point i can get on ith day by performing j type of activity on ith day
    // here I have 3 options to perform an acitvity either a b or c
    // but if i perform say a activity on ith day, i can't perform the same activity on (i-1)th day ot (i+1)th day

    // so i take 2d dp, what the max point i can got by performing j th activity on ith day
    // since there are 3 type of activity so a[][3]
    memset(dp, 0, sizeof(dp));
    dp[0][0]=a[0];
    dp[0][1]=b[0];
    dp[0][2]=c[0];

    for(int i=1; i<n; i++){
        // if ith day I perform a activity, then what's the max points I have got on (i-1)th day,
        // by not performing the same activity
        dp[i][0] = a[i] + max(dp[i-1][1], dp[i-1][2]);
        dp[i][1] = b[i] + max(dp[i-1][0], dp[i-1][2]); 
        dp[i][2] = c[i] + max(dp[i-1][0], dp[i-1][1]); 
        // cout<<dp[i][0]<<" "<<dp[i][1]<<" "<<dp[i][2]<<endl;
    }

    cout<<max(dp[n-1][0], max(dp[n-1][1], dp[n-1][2]))<<endl;
    return 0;
}