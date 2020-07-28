#include<iostream>
#include<vector>
#include<climits>
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

int calculateMinimumHP(vector<vector<int>>& dungeon) {
    int n=dungeon.size();
    if(n==0)return 0;
    int m = dungeon[0].size();

    vector<vector<int> >dp(n+1, vector<int>(m+1, INT_MAX));
    dp[n][m-1]=1;
    dp[n-1][m]=1;

    for(int i=n-1; i>=0; i--){
        for(int j=m-1; j>=0; j--){
            int val = min(dp[i][j+1], dp[i+1][j])-dungeon[i][j];
            dp[i][j] = max(1, val);
        }
    }
    return dp[0][0];
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