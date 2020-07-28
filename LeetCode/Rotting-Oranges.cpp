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

int n,m;

int dx[4]={1,-1,0,0};
int dy[4]={0,0,-1,1};

bool isValid(vector<vector<int>>& grid, int i, int j){
    return (i>=0 and i<n and j>=0 and j<m and grid[i][j]==1);
}

int orangesRotting(vector<vector<int>>& grid) {
    n = grid.size();
    m = n?grid[0].size():0;

    if(!n or !m)return -1;
    int ct=0;

    queue<pair<int, int> >q;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(grid[i][j]==2){
                q.push({i,j});
            }
            else if(grid[i][j]==1)ct++;
        }
    }
    if(ct==0)return 0;
    if(q.empty())return -1;

    int level=0;
    while(!q.empty()){
        int sz = q.size();
        for(int i=0; i<sz; i++){
            pair<int, int>top=q.front();
            q.pop();

            for(int k=0; k<4; k++){
                int nx = top.first+dx[k];
                int ny = top.second+dy[k];

                if(isValid(grid, nx, ny)){
                    q.push({nx, ny});
                    grid[nx][ny]=2;
                }
            }
        }
        level++;
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(grid[i][j]==1)return -1;
        }
    }
    return level-1;
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