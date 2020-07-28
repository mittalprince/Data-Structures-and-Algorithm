// https://leetcode.com/problems/island-perimeter/
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

int islandPerimeter(vector<vector<int>>& grid) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int ans=0;
    int n=grid.size();
    int m=n?grid[0].size():0;

    if(!n or !m)return 0;

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(grid[i][j]){
                ans += 4;

                int a = (i>0)?grid[i-1][j]:0;
                int b = (j>0)?grid[i][j-1]:0;
                int c = (i<n-1)?grid[i+1][j]:0;
                int d = (j<m-1)?grid[i][j+1]:0;

                // cout<<a<<b<<c<<d<<endl;
                ans -= (a+b+c+d);
            }
            // cout<<ans<<endl;
        }
    }
    return ans;
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