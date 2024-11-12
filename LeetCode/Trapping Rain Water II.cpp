// https://leetcode.com/problems/trapping-rain-water-ii/
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

int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};
#define ppi pair<int, pair<int, int>>

int trapRainWater(vector<vector<int>>& h) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n=h.size();
    int m=h[0].size();

    vector<vector<bool>>visited(n, vector<bool>(m, 0));
    auto cmp=[](const ppi a, const ppi b){
        return a.first>b.first;
    };
    priority_queue<ppi, vector<ppi>, decltype(cmp)>pq(cmp);

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(i==0 or j==0 or i==n-1 or j==m-1){
                pq.push({h[i][j], {i,j}});
                visited[i][j]=true;
            }
        }
    }
    int max_height=0;
    int ans=0;

    while(!pq.empty()){
        ppi top = pq.top();
        pq.pop();

        max_height = max(max_height, top.first);

        for(int k=0; k<4; k++){
            int i=top.second.first+dx[k];
            int j=top.second.second+dy[k];

            if(i>=0 and i<n and j>=0 and j<m and !visited[i][j]){
                if(h[i][j]<max_height){
                    ans += max_height-h[i][j];
                }
                visited[i][j]=true;
                pq.push({h[i][j], {i,j}});
            }
        }
    }
    return ans;
}

int main(){

/*
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
*/

    int n;
    cin>>n;
    vector<int> arr(n);
    
    return 0;
}