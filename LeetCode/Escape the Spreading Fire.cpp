// https://leetcode.com/problems/escape-the-spreading-fire/
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

// https://leetcode.com/problems/escape-the-spreading-fire/discuss/1995157/Solution-%2B-Intuition-%2B-Explanation-with-Pictures
bool isPossible(vector<vector<int>>& grid, vector<vector<int>>& dist, int wait_time){
    int n = grid.size();
    int m = grid[0].size();

    vector<vector<bool>>visited(n, vector<bool>(m, 0));
    queue<vector<int>>q;
    q.push({0,0,wait_time});
    visited[0][0] = true;

    while(!q.empty()){
        vector<int>top = q.front();
        q.pop();
        int x = top[0];
        int y = top[1];
        int d = top[2];

        for(int k=0; k<4; k++){
            int nx = x + dir[k][0];
            int ny = y + dir[k][1];

            if(!inBounds(nx, ny, n, m) || grid[nx][ny]==2 || visited[nx][ny]) continue;
            if(nx == n-1 && ny == m-1 && dist[nx][ny] >= d+1) return true;
            if (dist[nx][ny] <= d + 1) continue;
            q.push({nx, ny, d+1});
            visited[nx][ny] = true;
        }
    }
    return false;
}

bool inBounds(int i, int j, int n, int m) {
    return (0 <= i && i < n && 0 <= j && j < m);
} 
const int dir[4][4] = {{-1,0},{1,0},{0,1},{0,-1}};
int maximumMinutes(vector<vector<int>>& grid) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n = grid.size();
    int m = grid[0].size();

    vector<vector<int>>dist(n, vector<int>(m, INT_MAX));
    queue<vector<int>>q;

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(grid[i][j] == 1){
                q.push({i,j,0});
                dist[i][j] = 0;
            }
        }
    }

    while(!q.empty()){
        vector<int>top = q.front();
        q.pop();
        int x = top[0];
        int y = top[1];
        int d = top[2];

        for(int k=0; k<4; k++){
            int nx = x + dir[k][0];
            int ny = y + dir[k][1];

            if(!inBounds(nx, ny, n, m) || grid[nx][ny]==2 || dist[nx][ny] <= d+1) continue;
            q.push({nx, ny, d+1});
            dist[nx][ny] = d+1;
        }
    }
    int left = 0;
    int right = 1e9;
    int ans = -1;
    while(left<=right){
         int mid = left + (right - left) / 2;
        if(isPossible(grid, dist, mid)){
            ans = mid;
            left = mid+1;
        } else right=mid-1;
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