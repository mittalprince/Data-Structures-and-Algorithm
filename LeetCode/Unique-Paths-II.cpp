// https://leetcode.com/problems/unique-paths-ii/
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

int uniquePathsWithObstacles(vector<vector<int>>& arr) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n=arr.size();
    int m=arr[0].size();

    vector<vector<int> >dp(n, vector<int>(m, 0));

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(arr[i][j]==1){
                dp[i][j]=0;
                continue;
            }
            if(i==0 and j==0){
                dp[i][j]=1;
                continue;
            }
            if(i>0)dp[i][j] += dp[i-1][j];
            if(j>0)dp[i][j] += dp[i][j-1];
        }
    }

    return dp[n-1][m-1];
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