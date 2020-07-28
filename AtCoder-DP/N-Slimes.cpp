#include<iostream>
#include<vector>
#include<cstring>
#include<climits>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define MAX 405
#define Inf 1000000000005

int n;
ll arr[MAX];
ll dp[MAX][MAX]={0};

ll solve(){
    for(int d=1; d<n; d++){
        int i=0, j=d;
        while(j<n){
            ll ans = LLONG_MAX;
            for(int k=i; k<j; k++){
                ans = min(ans, dp[i][k]+dp[k+1][j]+(arr[j]-(i>0?arr[i-1]:0)));
            }
            dp[i][j]=ans;
            i++;
            j++;
        }
    }
    return dp[0][n-1];
}

int main(){
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>arr[i];
        if(i>0) arr[i] += arr[i-1];
    }
    cout<<solve()<<endl;
    return 0;
}