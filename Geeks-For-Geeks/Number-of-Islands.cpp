#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define MAX 105

const int x[] = {-1, -1, -1, 0, 0, 1, 1, 1};
const int y[] = {-1, 0, 1, -1, 1, -1, 0, 1};

bool canExist(vector<int> A[], bool visited[MAX][MAX], int n, int m, int x, int y){
    if(x<0 || y<0 || y>=m || x>=n || visited[x][y] || !A[x][y]) return false;
    return true;
}

void dfs(vector<int> A[], bool visited[MAX][MAX], int N, int M, int i, int j){
    
    visited[i][j]=true;
    
    for(int k=0; k<8; k++){
        if(canExist(A, visited, N, M, i+x[k], j+y[k])){
            dfs(A, visited, N, M, i+x[k], j+y[k]);
        }
    }
}

int findIslands(vector<int> A[], int N, int M) {
    
    bool visited[MAX][MAX];
    memset(visited, false, sizeof(visited));
    int ct=0;
    
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            if(!visited[i][j] && A[i][j]){
                dfs(A, visited, N, M, i, j);
                ct++;
            }
        }
    }
    return ct;
}
void solve(){
    int n,m,temp;
    cin>>n>>m;
    vector<int> A[n];
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>temp;
            A[i].push_back(temp);
        }
    }
    cout<<findIslands(A, n, m)<<endl;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}