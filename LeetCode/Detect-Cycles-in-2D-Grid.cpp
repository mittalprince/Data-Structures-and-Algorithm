// https://leetcode.com/contest/biweekly-contest-33/problems/detect-cycles-in-2d-grid/
//Reference : https://www.geeksforgeeks.org/detect-cycle-in-a-2d-grid/
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
vector<vector<char> >g;
int n,m;

int dx[4]={0,0,-1,1};
int dy[4]={1,-1,0,0};

bool isValid(int i, int j){
    return (i>=0 and i<n and j>=0 and j<m);
}

bool solve(int x, int y, int px, int py){
    visited[x][y]=true;

    for(int k=0; k<4; k++){
        int i=dx[k]+x;
        int j=dy[k]+y;

        if(isValid(i,j) and g[i][j]==g[x][y] and !(px==i and py==j)){
            if(visited[i][j])return true;
            bool check = solve(i,j, x,y);
            if(check)return true;
        }
    }
    return false;
}

bool containsCycle(vector<vector<char>>& grid) {
    n=grid.size();
    m=grid[0].size();

    g = grid;

    visited = vector<vector<bool> >(n, vector<bool>(m, 0));

    bool cycle=false;
    for(int i=0; i<n; i++){
        if(cycle)return true;
        for(int j=0; j<m; j++){
            if(!visited[i][j]){
                cycle = solve(i,j, -1, -1);
                if(cycle)return true;
            }
        }
    }

    return false;
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