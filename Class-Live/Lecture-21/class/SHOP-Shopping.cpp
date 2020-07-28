#include<iostream>
#include<vector>
#include<queue>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define debug(x) cout<<x<<"\n";
#define inf 2147483647
#define INF 9223372036854775807
#define MOD 1000000007

const int dx[] = {0, 0, 1, -1};
const int dy[] = {1, -1, 0, 0};
int dist[25][25]={0};
char arr[25][25]={0};

int src_x, src_y, dest_x, dest_y;
int n,m;

bool isValid(int i, int j){
    return (i>=0 and j>=0 and i<n and j<m and arr[i][j] != 'X');
}

void solve(){
    queue<pair<int, int> >q;
    q.push({src_x, src_y});
    dist[src_x][src_y]=0;

    while(!q.empty()){
        pair<int, int> front = q.front();
        q.pop();

        int old_x = front.first;
        int old_y = front.second;

        for(int i=0; i<4; i++){
            int new_x = old_x + dx[i];
            int new_y = old_y + dy[i];

            if(isValid(new_x, new_y) and (dist[new_x][new_y] > (dist[old_x][old_y] + (arr[old_x][old_y]-'0')))){
                dist[new_x][new_y] = dist[old_x][old_y]+(arr[old_x][old_y]-'0');
                q.push({new_x, new_y});
            }
        }
    }
}

int main(){

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    cin>>m>>n;
    while(n and m){
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                cin>>arr[i][j];
                // debug(arr[i][j])
                if(arr[i][j] == 'S'){
                    src_x=i;
                    src_y=j;
                    arr[i][j]='0';
                }
                else if(arr[i][j] == 'D'){
                    dest_x=i;
                    dest_y=j;
                    arr[i][j] = '0';
                }
                dist[i][j] = inf;
            }
        }
        solve();
        cout<<dist[dest_x][dest_y]<<endl;
        cin>>m>>n;
    }
    return 0;
}