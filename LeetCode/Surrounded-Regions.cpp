// https://leetcode.com/problems/surrounded-regions/
#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define debug(x) cout<<x<<"\n";
#define inf 1e9
#define INF 1e16
#define MOD 1000000007

vector<vector<char> >arr;
int n, m;
vector<vector<bool> >visited;

void dfs(int i, int j){
    if(i<0 or j<0 or i>=n or j>=m)return;
    if(arr[i][j] == 'X' || visited[i][j])return;

    visited[i][j]=true;

    dfs(i+1, j);
    dfs(i-1, j);
    dfs(i, j+1);
    dfs(i, j-1);
}

void solve(vector<vector<char>>& board) {
    n = board.size();
    if(!n)return;

    m = board[0].size();
    arr = board;
    visited = vector<vector<bool> >(n, vector<bool>(m, false));

    for(int i=0; i<n; i++){
        dfs(i, 0);
        dfs(i, m-1);
    }

    for(int i=0; i<m; i++){
        dfs(0, i);
        dfs(n-1, i);
    }


    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(board[i][j] == 'O' and !visited[i][j]){
                board[i][j]='X';
            }
        }
    }
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