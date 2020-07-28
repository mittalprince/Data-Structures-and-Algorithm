//https://practice.geeksforgeeks.org/problems/minimum-cost-path/0/
#include<iostream>
#include<vector>
#include<set>
#include<queue>
#include<climits>
using namespace std;
typedef long long ll;
#define MAX 105

const int dx[] = {0, 0, 1, -1};
const int dy[] = {1, -1, 0, 0};

int n;
int arr[MAX][MAX];

bool isValid(int i, int j){
    return (i>=0 and i<n and j>=0 and j<n);
}

ll solve(){
    
    vector<vector<int> >dist(n, vector<int>(n, INT_MAX));
    set<pair<ll, pair<int, int> > >q;   
    
    dist[0][0]=0;
    q.insert({arr[0][0], {0,0}});
    
    while(!q.empty()){
        pair<ll, pair<int, int> >top = *q.begin();
        q.erase(q.begin());
        
        ll parent_dist = top.first;
        int old_x = top.second.first;
        int old_y = top.second.second;
        
        if(old_x == n-1 and old_y==n-1){
            return parent_dist;
        }
        // cout<<parent_dist<<" "<<old_x<<" "<<old_y<<endl;
        for(int i=0; i<4; i++){
            int new_x = old_x+dx[i];
            int new_y = old_y+dy[i];
            
            if(!isValid(new_x, new_y))continue;
            // cout<<"here\n";
            
            // cout<<dist[new_x][new_y]<<" "<<parent_dist<<" "<<arr[new_x][new_y]<<endl;
            if(dist[new_x][new_y] > parent_dist+arr[new_x][new_y]){
                auto f = q.find({dist[new_x][new_y], {new_x,new_y}});
                if(f!=q.end()){
                    q.erase(f);
                }
                dist[new_x][new_y] = parent_dist+arr[new_x][new_y];
                q.insert({dist[new_x][new_y], {new_x,new_y}});
                // cout<<"here\n";
                if(new_x==n-1 and new_y==n-1){
                    // cout<<"enter\n";
                    return dist[new_x][new_y];
                }
            }
        }
    }
    return 0;
}

int main(){
    int t;
    cin>>t;
    while(t--){
       cin>>n; 
       for(int i=0; i<n; i++){
           for(int j=0; j<n; j++){
               cin>>arr[i][j];
           }
       }
       cout<<solve()<<endl;
    }
}
