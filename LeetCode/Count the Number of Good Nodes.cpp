// https://leetcode.com/problems/count-the-number-of-good-nodes/
#include<iostream>
#include<vector>
#include<unordered_map>
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

unordered_map<int, vector<int>>adj;
int good_nodes;

int solve(int i, int parent){
    int subtree_size=1;
    bool flag=true;
    int size=-1;

    for(auto it: adj[i]){
        if(it == parent)continue;
        int s = solve(it, i);
        if(size == -1) size = s;
        else if(size != s) flag = false;
        subtree_size += s;
    }
    if(flag) good_nodes++;
    return subtree_size;
}

int countGoodNodes(vector<vector<int>>& edges) {
    good_nodes = 0;
    for(auto it: edges){
        int u = it[0];
        int v = it[1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    solve(0, -1);
    return good_nodes;
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