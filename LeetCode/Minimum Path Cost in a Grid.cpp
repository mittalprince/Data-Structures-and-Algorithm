// https://leetcode.com/problems/minimum-path-cost-in-a-grid/
#include<iostream>
#include<vector>
#include<queue>
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

int minPathCost(vector<vector<int>>& grid, vector<vector<int>>& moveCost) {
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>>visitedCost(n, vector<int>(m, INT_MAX));
    priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>>pq;

    for(int i=0; i<m; i++){
        pq.push({grid[0][i], 0, i}); // dist, i, j
    }
    while(!pq.empty()){
        int costTillHere = pq.top()[0];
        int x = pq.top()[1];
        int y = pq.top()[2];
        pq.pop();

        if(x == n-1) return costTillHere;
        for(int dy=0; x+1<n && dy<m; dy++){
            int newCost = costTillHere + moveCost[grid[x][y]][dy] + grid[x+1][dy];
            if(newCost < visitedCost[x+1][dy]){
                visitedCost[x+1][dy] =  newCost;
                pq.push({newCost, x+1, dy});
            }
        }
    }
    return -1;
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