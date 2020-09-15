// https://www.youtube.com/watch?v=07mOSftOhrY
#include<iostream>
#include<vector>
#include<climits>
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

int minnode(int n, int keyval[], bool mstset[]) { 
  int mini = INT_MAX; 
  int mini_index = -1; 
  for (int i = 0; i < n; i++) { 
    if (mstset[i] == false && keyval[i] < mini) { 
      mini = keyval[i], mini_index = i; 
    } 
  } 
  return mini_index; 
} 
int solve(int n, vector<vector<int>> &city) {
    int parent[n]; 
    int keyval[n]; 
    bool mstset[n]; 
    for (int i = 0; i < n; i++) { 
        keyval[i] = numeric_limits<int>::max(); 
        mstset[i] = false; 
    } 
    parent[0] = -1; 
    keyval[0] = 0; 
    for (int i = 0; i < n - 1; i++) { 
        int u = minnode(n, keyval, mstset); 
        mstset[u] = true; 
        for (int v = 0; v < n; v++) { 
          if (city[u][v] && mstset[v] == false && 
              city[u][v] < keyval[v]) { 
            keyval[v] = city[u][v]; 
            parent[v] = u; 
          } 
        } 
      } 
      int cost = 0; 
      for (int i = 1; i < n; i++) {
          cost += city[parent[i]][i];
      }
    return cost;
}
int minCostConnectPoints(vector<vector<int>>& p) {
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);

    int n = p.size();
    vector<vector<int>> cost(n, vector<int>(n));
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cost[i][j] = abs(p[i][0] - p[j][0]) + abs(p[i][1] - p[j][1]);
        }
    }
    int ans = solve(n, cost);
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