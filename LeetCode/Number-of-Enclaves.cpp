#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define debug(x) cout<<x<<"\n";
#define MOD 1000000007

class Solution {
public:
    int n, m;
    void dfs(int x, int y, vector<vector<int>>& A){
        if( x<0 || y<0 || x>=n || y>=m || A[x][y]!=1){
            return;
        }
        A[x][y]=0;
        dfs(x+1, y, A), dfs(x, y+1, A), dfs(x-1, y, A), dfs(x, y-1, A);
    }
    

    int numEnclaves(vector<vector<int>>& A) {
        n = A.size();
        if(n==0) return 0;
        m = A[0].size();    
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if((i==0 || j==0 || i==n-1 || j== m-1) && A[i][j]==1){
                    dfs(i,j,A);  
                }
            }
        }
        
        int cnt = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(A[i][j] == 1){
                    cnt++;
                }
            }
        }
        return cnt;
    }
};

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