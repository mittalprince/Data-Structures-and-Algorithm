// Labyrinth
#include<iostream>
#include<vector>
#include<queue>
#include<list>
#include<unordered_map>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define debug(x) cout<<x<<"\n";
#define MOD 1000000007
#define MAX 2005

ll n,m,r,c,x,y;

const int dx[] = {0 ,0, 1, -1};
const int dy[] = {1, -1, 0, 0};
const int cost[] = {0, 1, 0, 0};

string maze[MAX];
ll dp[MAX][MAX];

bool isValid(ll i, ll j){
    return (i>=0 and i<n and j>=0 and j<m and maze[i][j] == '.');
}

void solve(){
    deque<pair<ll, ll> >q;
    memset(dp, -1, sizeof(dp));
    dp[r][c]=0;

    q.push_back({r,c});
    // debug("enter")
    while(!q.empty()){
        pair<ll, ll> front = q.front();
        q.pop_front();

        ll old_x = front.first;
        ll old_y = front.second;

        for(int i=0; i<4; i++){
            ll new_x = dx[i]+old_x;
            ll new_y = dy[i]+old_y;
            ll new_step_cost = cost[i];

            if(isValid(new_x, new_y)){
                if(dp[new_x][new_y]==-1 || dp[new_x][new_y]>dp[old_x][old_y]+new_step_cost){
                    dp[new_x][new_y] = dp[old_x][old_y]+new_step_cost;
                    if(new_step_cost){
                        q.push_back({new_x, new_y});
                    }
                    else{
                        q.push_front({new_x, new_y});
                    }
                }
            }
        }
    }
    // debug("exit");
    ll ans=0;
    for(ll i=0; i<n; i++){
        for(ll j=0; j<m; j++){
            ll left = dp[i][j];
            if(left != -1){
                ll right = left+j-c;
                if(left>=0 and left<=x and right >=0 and right <= y)ans++;
            }
        }
    }

    cout<<ans<<endl;
}

int main(){

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    cin>>n>>m>>r>>c>>x>>y;
    r--;
    c--;
 
    for(ll i=0; i<n; i++){
        cin>>maze[i];
    }
    // debug("work fine")
    solve();
    
    return 0;
}

/*
let (r, c) be the starting cell and (i, j) be the final cell
then number of right moves and number of left moves to reach (i, j) can be represented as-
c + right - left = j
therefore right = left + j - c
we will use this equation to find the total right and left moves
if they lie within the range of valid x(max right moves allowed) , y(max left moves allowed) we count that cell 
-> To make this a 0/1 BFS problem we will assign cost 1 to move left and 0 to rest(right, up, dowm)
that way we will be able to calculate the left moves
and subsequently we can find number of right moves
 
 */