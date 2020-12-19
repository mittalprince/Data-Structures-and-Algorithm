//https://leetcode.com/problems/cherry-pickup-ii/
#include<iostream>
#include<vector>
#include<cstring>
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

int dp[71][71][71];

int solve(vector<vector<int>>& grid, int n, int m, int r1, int c1, int c2){
    if(r1==n or c1<0 or c2<0 or c2>=m or c1>=m){
        return 0;
    }
    if(dp[r1][c1][c2]!=-1)return dp[r1][c1][c2];

    int ans=0;
    for(int i=-1; i<=1; i++){
        for(int j=-1; j<=1; j++){
            int nc1 = c1+i;
            int nc2 = c2+j;

            ans = max(ans, solve(grid, n, m, r1+1, nc1, nc2));
        }
    }
    ans += c1==c2?grid[r1][c1]:grid[r1][c1]+grid[r1][c2];
    return dp[r1][c1][c2]=ans;
}

int cherryPickup(vector<vector<int>>& grid) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n=grid.size();
    int m=grid[0].size();

    memset(dp, -1, sizeof(dp));
    return solve(grid, n, m, 0, 0, m-1);
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