#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);

const int x[] = {0,-1,1,0};
const int y[] = {-1,0,0,1};

bool canPlace(vector<vector<char> >&grid, vector<vector<bool> >&visited, int rows, int cols, int i, int j){
    if(i<0||i>=rows||j<0||j>=cols||visited[i][j]||(grid[i][j]=='0')) return false;
    return true;
}

void DFS(vector<vector<char> >&grid, vector<vector<bool> >&visited, int rows, int cols, int i, int j){
    visited[i][j] = true;

    for(int k=0; k<8; k++){
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
    int n,m;
    cin>>n>>m;
    vector<vector<char> > grid(n, vector<char>(m));
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>grid[i][j];
        }
    }
    return 0;
}