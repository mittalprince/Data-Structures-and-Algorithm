// https://leetcode.com/problems/maximize-the-number-of-target-nodes-after-connecting-trees-ii/
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

int dfs(int i, int p, const vector<vector<int>> &al, vector<bool> &parity, bool even = true) {
    int targets = even;
    parity[i] = even;
    for (int j : al[i])
        if (j != p)
            targets += dfs(j, i, al, parity, !even);
    return targets;
}
vector<vector<int>> adjacencyList(vector<vector<int>>& edges) {
    vector<vector<int>> al(edges.size() + 1);
    for (auto &e: edges) {
        al[e[0]].push_back(e[1]);
        al[e[1]].push_back(e[0]);            
    }        
    return al;
}
vector<int> maxTargetNodes(vector<vector<int>>& e1, vector<vector<int>>& e2) {
    /*
    For a node in the first tree, the answer is:
    a. the number of even or odd nodes (based on this node parity), plus:
    b. the largest of even and odd nodes in the second tree. this is because we can connect the current node in the first tree to either an even or odd node in the second tree. if even nodes are more connect with odd node so that we can add even in ans or vica versa
    */
    int m = e1.size() + 1, n = e2.size() + 1;
    vector<bool> parity(m), ingnored(n);
    int even1 = dfs(0, -1, adjacencyList(e1), parity), odd1 = m - even1;
    int even2 = dfs(0, -1, adjacencyList(e2), ingnored), odd2 = n - even2;
    vector<int> res(m);
    for (int i = 0; i < m; ++i)
        res[i] = max(even2, odd2) + (parity[i] ? even1 : odd1);
    return res;
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