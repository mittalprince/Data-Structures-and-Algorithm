// https://leetcode.com/problems/cherry-pickup/
#include<iostream>
#include<vector>
#include<climits>
#include<cstring>
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

// https://leetcode.com/problems/cherry-pickup/discuss/329945/Very-easy-to-follow-%3A-step-by-step-recursive-backtracking-with-memoization-N4.
int dp[51][51][51];
int n;
// Instead of going once from 0,0 to n-1,n-1 and then back, we simply go twice from 0,0 to n-1,n-1 because every path from n-1,n-1 to 0,0 can be interpreted as a path from 0,0 to n-1,n-1
// Note that the one person can never cross the past path of the other person (they can only meet at the same position) so we don't need to worry about one person picking up an already picked up cherry from the past
// What does a state represent? dp[r1][c1][c2] represents the max number of cherries that can be collected by 2 people going from r1,c1 and r2,c2 to n-1,n-1
// Transitions between states? we collect cherries on current positions of the two people (r1,c1 and r2,c2), then we go through all possible next states and choose the best one (max number of cherries) as the next state (we do this by adding the number of cherries of the best next state to the number of cherries we picked up on the current two positions of the people). In the end, the state dp[0][0][0] will contain the max number of cherries that can be picked up by going from 0,0 to n-1,n-1 and back.
int solve(vector<vector<int>>&grid, int r1, int c1, int c2){
    // we can deduce r2 because r1 + c1 == r2 + c2, since with each move either r or c of a person gets incremented by exactly one (Manhattan distance to origin stays equal)
    // this way we reduce the 4D dp problem to a 3D one (we save space by reducing the number of things we store in a state)
    int r2 = r1+c1-c2;
    // check if current state is out of bounds or on thorns
    if(r1>=n || c1>=n || r2>=n || c2>=n || grid[r1][c1] == -1 || grid[r2][c2] == -1){
        return INT_MIN;
    } 
    if(dp[r1][c1][c2] != -1)return dp[r1][c1][c2];

    // check if we reached the end state (note that if r1,c1 reached the end, this implies that r2,c2 also reached the end)

    if(r1 == (n-1) && c1 == (n-1))return grid[r1][c1];
    int result = grid[r1][c1];

    // in case the second person is on the same position, don't pick up the same cherry twice. Note that r1 == r2 <--> c1 == c2 (eg. they can't be on the same row without also being on the same column) 
    if(r1 != r2 && c1 != c2){
        result += grid[r2][c2];
    }
    int opt1 = solve(grid, r1+1, c1, c2); // down, down
    int opt2 = solve(grid, r1, c1+1, c2+1); // right, right
    int opt3 = solve(grid, r1+1, c1, c2+1); // down, right
    int opt4 = solve(grid, r1, c1+1, c2); // right, down

    return dp[r1][c1][c2] = result + max(opt1, max(opt2, max(opt3, opt4)));
}

int cherryPickup(vector<vector<int>>& grid) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    n = grid.size();
    memset(dp,-1,sizeof(dp));
    return max(0, solve(grid, 0, 0, 0));
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