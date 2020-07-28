// https://leetcode.com/problems/number-of-nodes-in-the-sub-tree-with-the-same-label/
#include<iostream>
#include<vector>
#include<functional>
#include<algorithm>
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

vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int>adj[n];
    vector<vector<int> >freq(n, vector<int>(26, 0));

    for(auto it: edges){
        adj[it[0]].push_back(it[1]);
        adj[it[1]].push_back(it[0]);
    }

    vector<bool>visited(n, 0);
    function<void(int)>dfs;
    dfs=[&](int src){
        visited[src]=true;
        freq[src][labels[src]-'a']++;

        for(int child: adj[src]){
            if(!visited[child]){
                dfs(child);
                for(int i=0; i<26; i++){
                    freq[src][i] += freq[child][i];
                }
            }
        }
    };

    // for(int i=0; i<n; i++){
    //     if(!visited[i]){
    //        dfs(i); 
    //     }
    // }
    dfs(0);

    vector<int>ans(n, 0);
    for(int i=0; i<n; i++){
        ans[i] = freq[i][labels[i]-'a'];
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