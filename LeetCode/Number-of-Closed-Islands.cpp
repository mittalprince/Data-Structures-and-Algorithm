// https://leetcode.com/problems/number-of-closed-islands/
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

int n,m;

vector<int>dir = {0,1,0,-1,0};

bool solve(vector<vector<int>>& grid, int i, int j){
    if(i<0 or j<0 or i>=n or j>=m)return false;
    if(grid[i][j])return true;

    grid[i][j]=true;
    int a = solve(grid, i+1, j);
    int b = solve(grid, i-1, j);
    int c = solve(grid, i, j+1);
    int d = solve(grid, i, j-1);

    return a && b && c && d;
}

int closedIsland(vector<vector<int>>& grid) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    n=grid.size();
    m = grid[0].size();
    int ans=0;

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(!grid[i][j])
                ans+= solve(grid, i, j);
        }
    }
    return ans;
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