// https://leetcode.com/problems/shortest-bridge/
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

/*
Lets select any one island and consider every point on it as start point
Use Multisource BFS
*/

int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};

queue<pair<int, int> >q;
int n,m;
vector<vector<bool> >visited;

void dfs(int i, int j, vector<vector<int>>& A){
    visited[i][j]=true;
    A[i][j]=0;
    q.push({i,j});

    for(int k=0; k<4; k++){
        int x = i + dx[k];
        int y = j + dy[k];
        if(x < 0 || x >= n || y < 0 || y >= m || A[x][y] == 0) {
              continue;
        }     
        dfs(x,y,A);
    }
}

int shortestBridge(vector<vector<int>>& A) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    n=A.size();
    m=A[0].size();

    visited = vector<vector<bool> >(n, vector<bool>(m, 0));

    bool flag=true;
    for(int i=0; i<n and flag; i++){
        for(int j=0; j<m; j++){
            if(A[i][j]==1){
                dfs(i,j, A);
                flag=false;
                break;
            }
        }
    }

    int ans=0;
    while(!q.empty()){
        int sz=q.size();
        ans++;
        for(int l=0; l<sz; l++){
            int i = q.front().first;
            int j = q.front().second;
            q.pop();

            if(A[i][j]==1){
                return ans-2;
            }
            for(int k = 0; k < 4; k++) {
                int x = i + dx[k];
                int y = j + dy[k];

                if(x < 0 || x >= n || y < 0 || y >= m || visited[x][y]) {
                      continue;
                }

                visited[x][y] = true;
                q.push({x, y});
            }
        }
    }

    return 0;
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