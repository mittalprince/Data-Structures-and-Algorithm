// https://leetcode.com/problems/number-of-islands/
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

bool canPlace(vector<vector<char> >&grid, vector<vector<bool> >&visited, int rows, int cols, int i, int j){
    if(i<0||i>=rows||j<0||j>=cols||visited[i][j]||(grid[i][j]=='0')) return false;
    return true;
}

void DFS(vector<vector<char> >&grid, vector<vector<bool> >&visited, int rows, int cols, int i, int j){
    const int x[] = {0,-1,1,0};
    const int y[] = {-1,0,0,1};
    visited[i][j] = true;

    for(int k=0; k<4; k++){
        if(canPlace(grid, visited, rows, cols, i+x[k], j+y[k])){
            DFS(grid, visited, rows, cols, i+x[k], j+y[k]);
        }
    }
}
int numIslands(vector<vector<char> >&grid){
    int rows = grid.size();
    if(rows == 0) return 0;
    int cols = grid[0].size();
    if(cols == 0) return 0;

    vector<vector<bool> >visited(rows, vector<bool>(cols, false));
    int ct=0;
    for(int i=0; i<rows; i++){
        for(int j=0; j<cols; j++){
            if(grid[i][j] == '1'  && !visited[i][j]){
                DFS(grid, visited, rows, cols ,i, j);
                ct++;
            }
        }
    }
    return ct;
}

int main(){

/*
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
*/

    int n;
    cin>>n;
    vector<int> arr(n);
    
    return 0;
}