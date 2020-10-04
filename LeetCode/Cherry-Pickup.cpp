// https://leetcode.com/problems/cherry-pickup/
#include<iostream>
#include<vector>
#include<cstring>
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

int dp[51][51][51];
int helper(vector<vector<int>>& grid,int r1,int c1,int c2,int n){
    int r2=r1+c1-c2;
    if(r1>=n || c1>=n || r2>=n || c2>=n || grid[r1][c1]==-1 || grid[r2][c2]==-1)
        return INT_MIN;
    if(dp[r1][c1][c2]!=-1) return dp[r1][c1][c2];
    if(r1==(n-1) && c1==(n-1)) return grid[r1][c1];
    int ans=grid[r1][c1];
    if(c1!=c2)
        ans+=grid[r2][c2];
    int temp=max(helper(grid,r1,c1+1,c2+1,n),helper(grid,r1+1,c1,c2+1,n));
    temp=max(temp,helper(grid,r1,c1+1,c2,n));
    temp=max(temp,helper(grid,r1+1,c1,c2,n));
    ans+=temp;
    return dp[r1][c1][c2]=ans;
}

int cherryPickup(vector<vector<int>>& grid) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    memset(dp,-1,sizeof(dp));
    int n=grid.size();
    return max(0,helper(grid,0,0,0,n));
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