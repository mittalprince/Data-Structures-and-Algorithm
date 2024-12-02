// https://leetcode.com/problems/matrix-block-sum/
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

int sizeX, sizeY;
int extractSum(int i, int j, const vector<vector<int> >& sum) {
    if (i < 0 || j < 0) return 0;
    if (i >= sizeX) i = sizeX - 1;
    if (j >= sizeY) j = sizeY - 1;
    return sum[i][j];
}

vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int K) {
    sizeX = mat.size();
    sizeY = mat[0].size();

    vector<vector<int>> sum(sizeX, vector<int>(sizeY, 0));
    // Calculate prefix matrix 
    for (int i = 0; i < sizeX; i++) {
        for (int j = 0; j < sizeY; j++) {
            sum[i][j] = mat[i][j] + extractSum(i-1, j, sum) + extractSum(i, j-1, sum) - extractSum(i-1, j-1, sum);
        }
    }

    // Use prefix matrix to calculate our sum
    vector<vector<int>> ans(sizeX, vector<int>(sizeY, 0));
    for (int i = 0; i < sizeX; i++) {
        for (int j = 0; j < sizeY; j++) {
            ans[i][j] = extractSum(i+K, j+K, sum) - extractSum(i+K, j-K-1,sum) - extractSum (i-K-1, j+K, sum) + extractSum(i-K-1, j-K-1, sum);
        }
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