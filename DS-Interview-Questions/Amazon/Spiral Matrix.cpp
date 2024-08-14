// https://leetcode.com/problems/spiral-matrix/
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

vector<int> spiralOrder(vector<vector<int>>& matrix){
    vector<vector<int>> dirs{{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    vector<int>res;
    int nr = matrix.size();
    int nc = matrix[0].size();

    vector<int>nSteps{nc, nr-1};
    int dir=0, ir=0, ic=-1;
    while(nSteps[dir%2]){
        for(int i=0; i<nSteps[dir%2]; i++){
            ir += dirs[dir][0];
            ic += dirs[dir][1];
            res.push_back(matrix[ir][ic]);
        }
        nSteps[dir%2]--;
        dir = (dir + 1) % 4;
    }
    return res;
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