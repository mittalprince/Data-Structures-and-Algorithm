// https://leetcode.com/problems/minimum-number-of-days-to-disconnect-island/
#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>
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
int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};

bool isValid(int i, int j){
    return (i>=0 and i<n and j>=0 and j<m);
}

bool dfs(vector<vector<int>>& g){
    vector<vector<bool>>visited(n, vector<bool>(m, 0));
    int ct=0;

    function<void(int, int)>dfs_helper;
    dfs_helper = [&](int i, int j){
        visited[i][j]=true;

        for(int k=0; k<4; k++){
            int x = i+dx[k];
            int y = j+dy[k];
            if(isValid(x,y) and g[i][j]==1){
                if(!visited[x][y])dfs_helper(x,y);
            }
        }
    };

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(g[i][j] and !visited[i][j]){
                dfs_helper(i,j);
                ct++;
            }
        }
    }
    return ct!=1;
}

int minDays(vector<vector<int>>& grid) {
    n=grid.size();
    m=grid[0].size();

    if(dfs(grid))return 0;

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(grid[i][j]==1){
                grid[i][j]=0;
                if(dfs(grid))return 1;
                grid[i][j]=1;
            }
        }
    }
    return 2;
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