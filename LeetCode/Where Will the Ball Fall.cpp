// https://leetcode.com/problems/where-will-the-ball-fall/
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

vector<int> findBall(vector<vector<int>>& grid) {
    int n=grid.size(), m=grid[0].size();
    vector<int>ans;
    // Each loop computes the result for when be drop a ball in column i.
    for (int i = 0; i < m; ++i) {
        int currRow = 0, currCol = i;
        while (currRow < n) {
            // We go to the right if the current value and the value to the right are both equal to 1.
            if (grid[currRow][currCol] == 1 && currCol + 1 < m && grid[currRow][currCol + 1] == 1) {
                currCol++; currRow++;
            // We go to the left if the current value and the value to the left are both equal to -1.
            } else if (grid[currRow][currCol] == -1 && currCol - 1 >= 0 && grid[currRow][currCol - 1] == -1) {
                currCol--; currRow++;
            } else {
                break;  // If we can't move to the left, and we can't move to the right, then the ball is stuck because there is no other way to move.
            }
        }
        ans.push_back(currRow == n ? currCol : -1);   // Store -1 if the ball got stuck.
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