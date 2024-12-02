// https://leetcode.com/problems/find-minimum-diameter-after-merging-two-trees/
#include<iostream>
#include<vector>
#include<queue>
#include<cmath>
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

int findDiameter(vector<vector<int>>&edges){
    // https://leetcode.com/problems/minimum-height-trees/ used this
    // https://leetcode.com/problems/find-minimum-diameter-after-merging-two-trees/discuss/5389938/Find-Diameter
    int n = edges.size()+1;
    vector<vector<int>>g(n+1);
    vector<int>degrees(n,0);
    for(auto& it: edges){
        g[it[0]].push_back(it[1]);
        g[it[1]].push_back(it[0]);
        degrees[it[0]]++;
        degrees[it[1]]++;
    }
    queue<int>leaves;
    for(int i=0; i<n; i++){
        if(degrees[i]==1)leaves.push(i);
    }
    int step=0, rem=n;
    while(rem > 2){
        int sz = leaves.size();
        rem -= sz;
        for(int i=0; i<sz; i++){
            int front = leaves.front();
            leaves.pop();
            for(int child: g[front]){
                degrees[child]--;
                if(degrees[child]==1)leaves.push(child);
            }
        }
        step++;
    }
    return rem == 2 ? 2*step+1 : 2*step;
}
int solve2(vector<vector<int>>& edges1, vector<vector<int>>& edges2){
    int diameter1 = findDiameter(edges1);
    int diameter2 = findDiameter(edges2);
    int dia1 = ceil(1.0*diameter1/2), dia2 = ceil(1.0*diameter2/2);
    return max(dia1+dia2+1, max(diameter1, diameter2));
}

int solve(vector<vector<int>> &adj, int st, int &farn){
    int n = adj.size();
    // farn = st;
    vector<int> dis(n, -1);
    helper(adj, st, 0, farn,dis);
    return dis[farn];
}

void helper(vector<vector<int>> &adj, int node, int distance, int &farn,vector<int> &dis){
    dis[node] = distance;
    if (distance > dis[farn])
        farn = node;
    for (auto it : adj[node])
        if (dis[it] == -1)
            helper(adj, it, distance + 1, farn,dis);
}
int minimumDiameterAfterMerge(vector<vector<int>> &nums1, vector<vector<int>> &nums2){
    int n = nums1.size();
    int m = nums2.size();
    vector<vector<int>> adj1(n + 1);
    vector<vector<int>> adj2(m + 1);
    for (auto &it : nums1)
    {
        adj1[it[1]].push_back(it[0]);
        adj1[it[0]].push_back(it[1]);
    }
    for (auto &it : nums2)
    {

        adj2[it[1]].push_back(it[0]);
        adj2[it[0]].push_back(it[1]);
    }

    int far1 = 0;
    solve(adj1, 0, far1);
    int diameter1 = solve(adj1, far1, far1);

    int far2 = 0;
    solve(adj2, 0, far2);
    int diameter2 = solve(adj2, far2, far2);

    // cout<<diameter1<<" "<<diameter2<<" ";
    return max({(diameter1 + 1) / 2 + (diameter2 + 1) / 2 + 1, diameter1, diameter2});
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