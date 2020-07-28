// https://leetcode.com/problems/coloring-a-border/
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

int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};
int n,m;
vector<vector<int> >visited;

void dfs(vector<vector<int>>& grid, int r0, int c0, int color){
    bool ans=false;
    visited[r0][c0]=1;

    for(int i=0; i<4; i++){
        int x=dx[i]+r0;
        int y=dy[i]+c0;

        if(x>=0 and x<n and y>=0 and y<m and !visited[x][y] and grid[x][y] == color){
            dfs(grid, x,y,color);
        }
        if(x>=0 and x<n and y>=0 and y<m and grid[x][y] != color){
            ans=true;
        }
    }
    if(r0==0 or r0==n-1 or c0==0 or c0==m-1 or ans){
        visited[r0][c0]=2;
    }
}

vector<vector<int>> colorBorder(vector<vector<int>>& grid, int r0, int c0, int color) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    n = grid.size();
    m = n?grid[0].size():0;

    if(!n or !m)return grid;

    visited = vector<vector<int> >(n, vector<int>(m, 0));
    dfs(grid, r0, c0, grid[r0][c0]);

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(visited[i][j]==2){
                grid[i][j]=color;
            }
        }
    }
    return grid;
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