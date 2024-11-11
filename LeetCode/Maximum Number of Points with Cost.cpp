// https://leetcode.com/problems/maximum-number-of-points-with-cost/
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

long long maxPoints(vector<vector<int>>& points) {
    // https://leetcode.com/problems/maximum-number-of-points-with-cost/discuss/1344908/C%2B%2BJavaPython-3-DP-Explanation-with-pictures-O(MN)-Time-O(N)-Space
    long long n = points.size();
    long long m = points[0].size();

    vector<long long>pre(m, 0);
    for(int i=0; i<m; i++) pre[i] = points[0][i];

    for(int i=0; i<n-1; i++){
        vector<long long> left(m,0), right(m,0), curr(m,0);
        left[0] = pre[0];
        right[m-1] = pre[m-1];
        for(int j=1; j<m; j++){
            left[j] = max(left[j-1]-1, pre[j]);
        }
        for(int j=m-2; j>=0; j--){
            right[j] = max(right[j+1]-1, pre[j]);
        }
        for(int j=0; j<m; j++){
            curr[j] = points[i+1][j] + max(left[j], right[j]);
        }
        pre = curr;
    }

    return *max_element(pre.begin(), pre.end());
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