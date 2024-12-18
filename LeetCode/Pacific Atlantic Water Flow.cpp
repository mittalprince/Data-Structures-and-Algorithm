// https://leetcode.com/problems/pacific-atlantic-water-flow/
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

class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& matrix) {
        if (!matrix.size() || !matrix[0].size()) 
            return res;
        
        n = matrix.size();
        m = matrix[0].size();
        states.assign(n,vector<int> (m, 0));
        
        for (int i = 0; i < n; i++) {
            recDFS(matrix, i, 0, INT_MIN, 1);
            recDFS(matrix, i, m-1, INT_MIN, 2);
        }
        
        for (int i = 0; i < m; i++) {
            recDFS(matrix, 0, i, INT_MIN, 1);
            recDFS(matrix, n-1, i, INT_MIN, 2);
        }
        
        return res;
    }
    
private:
    vector<vector<int>> res, states;
    vector<int> x_points = {1, 0, -1, 0};
    vector<int> y_points = {0, 1, 0, -1};
    int m, n;
    
    bool isValid(int x, int y) {
        return x < n and x >= 0 and y < m and y >= 0;
    }
    
    void recDFS(vector<vector<int>>& mat, int x, int y, int prev, int prev_state) {
        if (!isValid(x, y) || mat[x][y] < prev || states[x][y] == prev_state || states[x][y] == 3) 
            return;
        
        states[x][y] += prev_state;
        
        if (states[x][y] == 3) 
            res.push_back({x, y});
        
        for (int i = 0; i < 4; i++) {
            recDFS(mat, x + x_points[i], y + y_points[i], mat[x][y], prev_state);
        }
    }
};

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