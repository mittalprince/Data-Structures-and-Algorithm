//https://leetcode.com/problems/minimum-jumps-to-reach-home/
#include<iostream>
#include<vector>
#include<climits>
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

int minimumJumps(vector<int>& forbidden, int a, int b, int x) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int>valid(4005,1);
    for(int i: forbidden)valid[i]=0;

    int dp[4005][2]; // dp[i][j]-> min jumpsto reach ith position including j backward jumps

    memset(dp, -1, sizeof(dp));

    dp[0][0]=0;
    queue<pair<int,int> >q;
    q.push({0,0});

    while(!q.empty()){
        pair<int,int>top = q.front();
        q.pop();

        if(top.first+a<4005 and valid[top.first+a] and dp[top.first+a][0]==-1){
            q.push({top.first+a, 0});
            dp[top.first+a][0]=dp[top.first][top.second]+1;
        }
        if(top.second==0 and top.first-b>=0 and valid[top.first-b] and dp[top.first-b][1]==-1){
            q.push({top.first-b, 1});
            dp[top.first-b][1]=dp[top.first][0]+1;
        }
    }
    // cout<<dp[x][0]<<" "<<dp[x][1]<<endl;
    if(dp[x][0]==-1 and dp[x][1]==-1)return -1;
    if(dp[x][0]==-1)dp[x][0]=INT_MAX;
    if(dp[x][1]==-1)dp[x][1]=INT_MAX;

    return min(dp[x][1], dp[x][0]);
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