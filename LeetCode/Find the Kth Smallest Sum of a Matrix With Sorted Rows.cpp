// https://leetcode.com/problems/find-the-kth-smallest-sum-of-a-matrix-with-sorted-rows/
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

/*
int kthSmallest(vector<vector<int>>& mat, int k) {
    int m = mat.size(), n = mat[0].size();
    int left = m, right = m * 5000, ans = -1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        int cnt = countArraysHaveSumLessOrEqual(mat, m, n, mid, 0, 0, k);
        if (cnt >= k) {
            ans = mid;
            right = mid - 1;
        } else left = mid + 1;
    }
    return ans;
}
int countArraysHaveSumLessOrEqual(vector<vector<int>>& mat, int m, int n, int targetSum, int r, int sum, int k) {
    if (sum > targetSum) return 0;
    if (r == m) return 1; // found a valid array with sum <= targetSum
    int ans = 0;
    for (int c = 0; c < n; ++c) {
        int cnt = countArraysHaveSumLessOrEqual(mat, m, n, targetSum, r + 1, sum + mat[r][c], k - ans);
        if (cnt == 0) break; // prune, the array (which contains mat[r][c]) has sum > targetSum -> No need to process anymore
        ans += cnt;
        if (ans > k) break; // Important prune, since count > k -> No need to process anymore
    }
    return ans;
}
*/
int kthSmallest(vector<vector<int>>& mat, int k) {        
    vector<int> row(mat[0]);
    for(int i = 1; i < mat.size(); ++i) {
        vector<int> nr;  // next row
        for(int j = 0; j < mat[i].size(); ++j)                          
            for(auto pathSum : row) 
                nr.push_back(mat[i][j] + pathSum); // all possible path ends at [i,j] by far                    

        sort(nr.begin(), nr.end());            
        nr.resize( min(k, int(nr.size())) );
        row=move(nr);                
    }        
    return row[k-1];
    //return row.back(); //ok
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