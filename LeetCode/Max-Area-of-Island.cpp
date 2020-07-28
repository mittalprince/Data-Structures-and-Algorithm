// https://leetcode.com/problems/max-area-of-island/
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

vector<vector<bool> >visited;
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};
int n,m, ans=0, curr=0;

void solve(vector<vector<int>>& grid, int i, int j){
    if(i<0 or i>=n or j<0 or j>=m or visited[i][j] or !grid[i][j])return;
    curr++;

    visited[i][j]=true;

    for(int k=0; k<4; k++){
        solve(grid, i+dx[k], j+dy[k]);
    }
}

int maxAreaOfIsland(vector<vector<int>>& grid) {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    n=grid.size();
    m=n?grid[0].size():0;

    if(!n or !m)return 0;

    visited = vector<vector<bool> >(n, vector<bool>(m, false));

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(!visited[i][j]){
                curr=0;
                solve(grid, i,j);
                ans = max(ans, curr);
            }
        }
    }

    return ans;
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