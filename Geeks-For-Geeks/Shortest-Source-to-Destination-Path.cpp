#include<iostream>
#include<vector>
#include<queue>
#include<map>
using namespace std;
#define MAX 25

bool arr[MAX][MAX];
vector<vector<bool> >visited;
int n,m,x,y;

const int dx[] = {0, 0, 1, -1};
const int dy[] = {1, -1, 0, 0};

bool isValid(int i, int j){
    return (i>=0 and i<n and j>=0 and j<m and arr[i][j] and !visited[i][j]);
}

int solve(){
    
    vector<vector<int> >dist(n, vector<int>(m, 0));
    
    queue<pair<int, int> >q;
    q.push({0,0});
    visited[0][0]=true;
    dist[0][0]=0;
    
    
    
    while(!q.empty()){
        pair<int, int>top = q.front();
        q.pop();
        
        int old_x = top.first;
        int old_y = top.second;
        
        for(int i=0; i<4; i++){
            int new_x = old_x+dx[i];
            int new_y = old_y+dy[i];
            
            if(!isValid(new_x, new_y))continue;
            
            visited[new_x][new_y]=true;
            q.push({new_x,new_y});
            dist[new_x][new_y] = dist[old_x][old_y]+1;
            
            if(new_x == x and new_y == y){
                return dist[new_x][new_y];
            }
        }
    }
    return -1;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        cin>>n>>m;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                cin>>arr[i][j];
            }
        }
        cin>>x>>y;
        visited = vector<vector<bool> >(n, vector<bool>(m, false));
        if(!arr[0][0] || !arr[x][y]){
            cout<<"-1\n";
        }
        else if(x==0 and y==0){
            cout<<"0\n";
        }
        else cout<<solve()<<endl;
    }
}