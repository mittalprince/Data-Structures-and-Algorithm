// https://leetcode.ca/all/265.html
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

int minCostII(vector<vector<int>>& costs){
    int n = costs.size();
    int k = costs[0].size();

    vector<vector<int>>dp(n, vector<int>(k, INT_MAX));
    int least = INT_MAX;
    int s_least = INT_MAX;

    for(int j=0; j<k; j++){
        dp[0][j] = costs[0][j];
        if (costs[0][j] <= least){
            s_least = least;
            least = costs[0][j];
        } else if(costs[0][j] <= s_least){
            s_least = costs[0][j];
        }
    }

    for(int i=1; i<n; i++){
        int nleast = INT_MAX;
        int ns_least = INT_MAX;
        for(int j=0; j<k; j++){
            if(least == dp[i-1][j]){
                dp[i][j] = s_least + costs[i][j];
            } else {
                dp[i][j] = least + costs[i][j];
            }

            if(dp[i][j] <= nleast){
                ns_least = nleast;
                nleast = dp[i][j];
            } else if(dp[i][j] <= ns_least){
                ns_least == dp[i][j];
            }
        }

        least = nleast;
        s_least = ns_least;
    }
    return least;
}

int minCostII(vector<vector<int>>& costs) {
    int n = costs.size(), k = costs[0].size();
    vector<int> f = costs[0];
    for (int i = 1; i < n; ++i) {
        vector<int> g = costs[i];
        for (int j = 0; j < k; ++j) {
            int t = INT_MAX;
            for (int h = 0; h < k; ++h) {
                if (h != j) {
                    t = min(t, f[h]);
                }
            }
            g[j] += t;
        }
        f = move(g);
    }
    return *min_element(f.begin(), f.end());
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