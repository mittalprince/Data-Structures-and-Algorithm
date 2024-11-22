// https://algo.monster/liteproblems/505
#include<iostream>
#include<vector>
#include<cstring>
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

int shortestDistance(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination){
    int rows = maze.size();
    int cols = maze[0].size();

    int dist[rows][cols];
    memset(dist, 0x3f, sizeof(dist));
    int startRow = start[0], startCol = start[1];
    int destRow = destination[0], destCol = destination[1];
    dist[startRow][startCol] = 0;
    queue<pair<int, int>>q;
    q.push({startRow, startCol});

    int dirs[5] = {-1, 0, 1, 0, -1};
    while(!q.empty()){
        pair<int, int>top = q.front();
        int currRow = top.first, currCol = top.second;
        q.pop();
        for(int i=0; i<4; i++){
            int x = currRow, y = currCol;
            int d = dist[currRow][currCol];
            int rowDir = dirs[i], colDir = dirs[i + 1];
            while(x+rowDir >=0 && x+rowDir<rows && y+colDir >= 0 && y+colDir<cols && maze[x+rowDir][y+colDir] == 0){
                x += rowDir;
                y += colDir;
                d++;
            }
            if(d < dist[x][y]){
                dist[x][y] = d;
                q.push({x, y});
            }
        }
    }
    return dist[destRow][destCol] == 0x3f3f3f3f ? -1 : dist[destRow][destCol];
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