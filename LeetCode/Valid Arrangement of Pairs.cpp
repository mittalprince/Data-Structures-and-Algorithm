// https://leetcode.com/problems/valid-arrangement-of-pairs/
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

unordered_map<int, vector<int>> adj;
unordered_map<int, int> deg;// net outdegree
inline void build_graph(vector<vector<int>>& pairs){
    for(auto& edge: pairs){
        int start=edge[0], end=edge[1];
        adj[start].push_back(end);
        deg[start]++;
        deg[end]--;
    }
}

vector<int> rpath;
inline void euler(int i){
    vector<int> stk={i};
    while(!stk.empty()){
        i = stk.back();
        if(adj[i].empty()){
            rpath.push_back(i);
            stk.pop_back();
        } 
        else {
            int j=adj[i].back();
            adj[i].pop_back();
            stk.push_back(j);
        }
    }
}

vector<vector<int>> validArrangement(vector<vector<int>>& pairs) {
    const int e = pairs.size();
    adj.reserve(e);
    deg.reserve(e);

    build_graph(pairs);

    int i0=deg.begin()->first;
    //Find start vertex for Euler path 
    for (auto& [v, d]: deg){
        if (d == 1){
            i0=v;
            break;
        } 
    }

    euler(i0);

    vector<vector<int>> ans;
    ans.reserve(e);

    for (int i=rpath.size()-2; i>=0; i--) 
        ans.push_back({rpath[i+1], rpath[i]});

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