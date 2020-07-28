// https://practice.geeksforgeeks.org/problems/find-whether-path-exist/0/
#include<iostream>
#include<vector>
#include<queue>
#include<map>
using namespace std;
#define MAX 25

bool arr[MAX][MAX];
vector<vector<bool> >visited;
int n,m,src_x,src_y,x,y;

const int dx[] = {0, 0, 1, -1};
const int dy[] = {1, -1, 0, 0};

bool isValid(int i, int j){
    return (i>=0 and i<n and j>=0 and j<m and arr[i][j] and !visited[i][j]);
}

bool solve(){
    

    queue<pair<int, int> >q;
    q.push({src_x,src_y});
    
    visited[src_x][src_y]=true;
    
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
            
            if(new_x == x and new_y == y){
                return true;
            }
        }
    }
    return false;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        cin>>n;
        m=n;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                int a;
                cin>>a;
                if(a == 1){
                    src_x=i, src_y=j;
                    arr[i][j]=1;
                }
                else if(a == 2){
                    x=i;
                    y=j;
                    arr[i][j]=1;
                }
                else if(a==3){
                    arr[i][j]=1;
                }
                else arr[i][j]=0;
            }
        }
        
        visited = vector<vector<bool> >(n, vector<bool>(m, false));
        
        cout<<solve()<<endl;
    }
}