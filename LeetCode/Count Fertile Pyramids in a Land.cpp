// https://leetcode.com/problems/count-fertile-pyramids-in-a-land/
#include<iostream>
#include<vector>
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

int count(vector<vector<int>> grid){
    int n = grid.size(), m = grid[0].size(), ans = 0;
    for(int i = 1; i < n; i++){
        for(int j = 1; j < m - 1; j++){
            if(grid[i][j] && grid[i - 1][j]){ // check if current cell can be a tip of pyramid or not.
                grid[i][j] = min(grid[i - 1][j - 1], grid[i - 1][j + 1]) + 1; // if its a pyramid, find the height.
                ans += grid[i][j] - 1;
                // pyramid of size n contributes n - 1 times to the answer.
            }
        }
    }
    return ans;
}
int countPyramids(vector<vector<int>>& grid) {
    int ans = count(grid);
    reverse(grid.begin(), grid.end());
    ans += count(grid);
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