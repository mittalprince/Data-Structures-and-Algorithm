//https://leetcode.com/problems/maximum-non-negative-product-in-a-matrix/
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
// #define MOD 1000000007

const int MOD = 1000000007;

int maxProductPath(vector<vector<int>>& grid) {
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);

    int n=grid.size();
    int m=grid[0].size();

    vector<vector<long long> >mx(n, vector<long long>(m, 0));
    vector<vector<long long> >mi(n, vector<long long>(m, 0));


    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(i==0 and j==0){
                mx[0][0] = mi[0][0] = grid[0][0];
            }
            else if(i==0){
                mx[i][j] = mi[i][j] = grid[i][j]*mx[i][j-1];
            }
            else if(j==0){
                mx[i][j] = mi[i][j] = grid[i][j]*mx[i-1][j];
            }
            else{
                if(grid[i][j]<0){
                    mx[i][j] = min(mi[i-1][j], mi[i][j-1])*grid[i][j];
                    mi[i][j] = max(mx[i-1][j], mx[i][j-1])*grid[i][j];
                }
                else{
                    mi[i][j] = min(mi[i-1][j], mi[i][j-1])*grid[i][j];
                    mx[i][j] = max(mx[i-1][j], mx[i][j-1])*grid[i][j];
                }
            }
        }
    }

    int ans = mx[n-1][m-1]%MOD;
    return ans<0?-1:ans;
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