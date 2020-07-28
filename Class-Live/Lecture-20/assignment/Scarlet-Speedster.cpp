#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<climits>
#include<map>
#include<cstring>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define debug(x) cout<<x<<"\n";
#define MOD 1000000007

ll n,m,x,y;
vector<vector<ll> >adj;
vector<vector<bool> >visited;

const int dx[] ={0, 0, 1, -1};
const int dy[] ={1, -1, 0, 0};

bool isValid(int i, int j){
    return (i>=0 and j>=0 and i<n and j<m and !visited[i][j]);
}

int BFS(bool even=true){

    deque<pair<int, pair<int, int> > >q;
    q.push_back({0, {0,0}});
    visited[0][0]=true;

    while(!q.empty()){
        pair<int, pair<int, int> >front = q.front();
        q.pop_front();

        int old_x = front.second.first;
        int old_y = front.second.second;
        int dist = front.first;

        for(int i=0; i<4; i++){
            int new_x = old_x+dx[i];
            int new_y = old_y+dy[i];

            if(!isValid(new_x, new_y))continue;
            if(even){
                visited[new_x][new_y]=true;
                if((adj[old_x][old_y]&1) == (adj[new_x][new_y]&1)){
                    q.push_front({dist, {new_x,new_y}});
                    if(new_x == n-1 and new_y==m-1)return dist;
                }
                else{
                    q.push_back({dist+1, {new_x,new_y}});
                    if(new_x == n-1 and new_y==m-1)return dist+1;
                }
            }
            else{
                visited[new_x][new_y]=true;
                if((adj[old_x][old_y]&1) != (adj[new_x][new_y]&1)){
                    q.push_front({dist, {new_x,new_y}});
                    if(new_x == n-1 and new_y==m-1)return dist;
                }
                else{
                    q.push_back({dist+1, {new_x,new_y}});
                    if(new_x == n-1 and new_y==m-1)return dist+1;
                }
            }
        }
    }

    return INT_MAX;
}

void solve(){
    cin>>n>>m>>x>>y;

    adj = vector<vector<ll> >(n, vector<ll>(m));
    visited = vector<vector<bool> >(n, vector<bool>(m, false));

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>adj[i][j];
        }
    }    

    ll flash_dist = BFS();
    flash_dist *= x;
    
    visited = vector<vector<bool> >(n, vector<bool>(m, false));

    ll reverse_flash_dist = BFS(false);
    reverse_flash_dist *= y;

    if(flash_dist<reverse_flash_dist){
        cout<<"YES\n";
    }
    else cout<<"NO\n";

}

int main(){

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}