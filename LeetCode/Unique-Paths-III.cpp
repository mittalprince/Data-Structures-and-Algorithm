// https://leetcode.com/problems/unique-paths-iii/
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

int n,m,ans,total;

void dfs(vector<vector<int>>& grid, int i, int j, int ct){
    if(i<0 or j<0 or i>=n or j>=m or grid[i][j]==-1)return;

    if(grid[i][j]==2){
        ans += ct==total;
        return;
    }
    if(ct>=total)return;

    grid[i][j]=-1;
    dfs(grid, i-1, j, ct+1);
    dfs(grid, i+1, j, ct+1);
    dfs(grid, i, j-1, ct+1);
    dfs(grid, i, j+1, ct+1);
    grid[i][j]=0;
}

int uniquePathsIII(vector<vector<int>>& grid) {
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);

    n=grid.size();
    m=(n==0)?0:grid[0].size();

    if(n==0 or m==0)return 0;

    int start_x, start_y;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(grid[i][j]==1){
                start_x=i, start_y=j;
            }
            else if(grid[i][j]==0){
                total++;
            }
        }
    }
    total++;
    dfs(grid, start_x, start_y, 0);

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