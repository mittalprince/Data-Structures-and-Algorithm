// https://leetcode.com/problems/shortest-path-in-a-grid-with-obstacles-elimination/
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

int solve(vector<vector<int>>& grid,int k){
    // At a particular cell we will store the number of obstacles that we can still remove after walking through that cell
    vector<vector<int>> vis(grid.size(),vector<int>(grid[0].size(),-1));
    queue<vector<int>> q;

    // queue stores (x,y,current path length,number of obstacles we can still remove)
    q.push({0,0,0,k});
    while(!q.empty()){
        auto t=q.front();
        int x=t[0],y=t[1];
        q.pop();

        // Exit if current position is outside of the grid
        if(x<0 || y<0 || x>=grid.size() || y>=grid[0].size()){
            continue;
        }

        // Destination found
        if(x==grid.size()-1 && y==grid[0].size()-1)
            return t[2];

        if(grid[x][y]==1){
            if(t[3]>0) // If we encounter an obstacle and we can remove it
                t[3]--;
            else
                continue;
        }

        // The cell was previously visited by some path and we were able to remove more obstacles from the previous path.
        // Then we don't need to continue on our current path
        if(vis[x][y]!=-1 && vis[x][y]>=t[3])
            continue;
        vis[x][y]=t[3];

        q.push({x+1,y,t[2]+1,t[3]});
        q.push({x,y+1,t[2]+1,t[3]});
        q.push({x-1,y,t[2]+1,t[3]});
        q.push({x,y-1,t[2]+1,t[3]});

    }
    return -1;
}

int shortestPath(vector<vector<int>>& grid, int k) {
    return solve(grid,k);
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