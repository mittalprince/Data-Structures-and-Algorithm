// https://leetcode.com/problems/shortest-path-in-binary-matrix/
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

shortestPathBinaryMatrix(vector<vector<int>>& grid) {
    int r = grid.size();
    int c = grid[0].size();
    int ans = 0;
    int d[8][2] = {{-1,-1},{-1,0},{-1,1},{0,-1},{0,1},{1,-1},{1,0},{1,1}};
    queue<pair<int,int>> qu;
    vector<vector<bool>> visit(r,vector(c,false));

    if(grid[0][0] == 1 || grid[r-1][c-1] == 1){
        return -1;
    }

    qu.push(make_pair(0,0));
    visit[0][0] = true;

    while(!qu.empty()){
        int steps = qu.size();
        ans++;

        /*directions*/
        for(int i = 0;i < steps; ++i){
            int x = qu.front().first;
            int y = qu.front().second;
            qu.pop();
            if(x == r-1 && y == c-1){
                return ans;
            }

            for(int j = 0;j < 8; ++j){
                int x1 = x + d[j][0];
                int y1 = y + d[j][1];
                if(x1 >= 0 && x1 < r && y1 >= 0 && y1 < c){
                    if(!visit[x1][y1] && !grid[x1][y1]){
                        qu.push(make_pair(x1,y1));
                        visit[x1][y1] = true;
                    }
                }
            }
        }
    }

    return -1;
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