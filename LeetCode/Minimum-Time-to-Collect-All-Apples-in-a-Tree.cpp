// https://leetcode.com/problems/minimum-time-to-collect-all-apples-in-a-tree/
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

int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
    vector<vector<int>>adj(n);
    for(auto it: edges){
        adj[it[0]].push_back(it[1]);
        adj[it[1]].push_back(it[0]);
    }
    vector<bool>visited(n, false);
    function<int(int)>dfs_helper = [&](int src)->int{
        if(visited[src])return 0;
        visited[src]=true;
        int res=0;
        for(int child: adj[src]){
            if(!visited[child]){
                res += dfs_helper(child);
            }
        }
        if((res > 0 || hasApple[src]) && src != 0) res += 2;
        return res;
    };

    return dfs_helper(0);
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