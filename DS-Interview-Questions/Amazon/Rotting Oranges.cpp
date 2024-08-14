// https://leetcode.com/problems/rotting-oranges/
#include<iostream>
#include<vector>
#include<queue>
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

int dir[4][4] = {{0,1},{1,0}, {-1,0}, {0,-1}};
int n,m;

bool isValid(vector<vector<int>>& grid, int i, int j){
    return (i>=0 && i<n && j>=0 && j<m && grid[i][j]==1);
}
int orangesRotting(vector<vector<int>>& grid){
    n = grid.size();
    m = grid[0].size();

    int ct=0;
    queue<pair<int,int>>q;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(grid[i][j]==2)q.push({i,j});
            else if(grid[i][j]==1) ct++;
        }
    }
    if(!ct)return 0;
    if(q.empty())return -1;

    int ans=0;
    while(!q.empty()){
        int sz = q.size();
        for(int i=0; i<sz; i++){
            pair<int, int> top = q.front();
            q.pop();

            for(int j=0; j<4; j++){
                int nx = top.first + dir[j][0];
                int ny = top.second+ dir[j][1];
                if(isValid(grid, nx, ny)){
                    q.push({nx, ny});
                    grid[nx][ny]=2;
                }
            }
        }
        ans++;
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(grid[i][j]==1)return -1;
        }
    }
    return ans;
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