// https://leetcode.com/problems/detonate-the-maximum-bombs/
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

int maximumDetonation(vector<vector<int>>& bs) {
    int res = 0, sz = bs.size();
    vector<vector<int>> al(bs.size()); 
    for(int i=0; i<sz; i++){
        long long x = bs[i][0], y = bs[i][1], r = (long long) bs[i][2]*bs[i][2];
        for(int j=0; j<sz; j++){
            if(i!=j && ((x-bs[j][0])*(x-bs[j][0]) + (y-bs[j][1])*(y-bs[j][1])) <= r){
                al[i].push_back(j);
            }
        }
    }
    int ans=0,ct=0;

    function<void(int, vector<bool>&)>dfs = [&](int src, vector<bool>&visited){
        visited[src]=true;
        ct++;
        for(int child: al[src]){
            if(!visited[child]) dfs(child,visited);
        }
    };
    for(int i=0; i<sz; i++){
        ct=0;
        vector<bool>visited(sz, 0);
        dfs(i, visited);
        ans = max(ans,  ct);
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