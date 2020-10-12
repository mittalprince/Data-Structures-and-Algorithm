// https://leetcode.com/problems/count-subtrees-with-max-distance-between-cities/
#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
#include<set>
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

unordered_map<int, set<int> > g;

int dfs(int u, int parent, int &subtree, int &mx){
    vector<int>arr = {0,0};
    subtree = subtree ^ (1 << (u - 1));  //clear visited Node bit.

    for(int child: g[u]){
        if(child==parent)continue;
        if((subtree & (1 << (child - 1))) == 0) continue;//the next node is not included in the subtree, ignore this node.
        int res = dfs(child, u, subtree, mx) + 1;
        arr.push_back(res);
    }

    sort(arr.rbegin(), arr.rend());
    mx = max(mx, arr[0] + arr[1]);
    return arr[0];
}

vector<int> countSubgraphsForEachDiameter(int n, vector<vector<int>>& edges) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int>ans(n-1);
    for(vector<int> edge: edges){
        g[edge[0]].insert(edge[1]);
        g[edge[1]].insert(edge[0]);
    }

    int size = 1<<n;
    for(int i=1; i<size; i++){
        if((i&(i-1))==0)continue; // subtree contain only one node
        int subtree=i;
        int mx=0;
        int u=0;
        for(int j=0; j<n; j++){
            if((1<<j)&i){
                u=j+1;
                break;
            }
        }
        int res = dfs(u, -1, subtree, mx);
        if(subtree==0) ans[mx-1]++;
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