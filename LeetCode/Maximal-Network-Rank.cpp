// https://leetcode.com/problems/maximal-network-rank/
#include<iostream>
#include<vector>
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

int maximalNetworkRank(int n, vector<vector<int>>& roads) {
    vector<int>inDeg(n, 0);
    vector<vector<int> >adj(n, vector<int>(n, 0));

    for(int i=0; i<roads.size(); i++){
        int a=roads[i][0];
        int b=roads[i][1];
        inDeg[a]++;
        inDeg[b]++;

        adj[a][b]=1;
        adj[b][a]=1;
    }
    int ans=0;
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            int r = inDeg[i]+inDeg[j]-adj[i][j];
            ans = max(ans, r);
        }
    }
    return ans;
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