// https://leetcode.com/problems/find-valid-matrix-given-row-and-column-sums/
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

vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n=rowSum.size();
    int m=colSum.size();

    vector<vector<int> >ans(n, vector<int>(m, 0));

    for(int i=0, j=0; i<n and j<m;){
        int x = min(rowSum[i], colSum[j]);
        ans[i][j] += x;
        rowSum[i] -= x;
        colSum[j] -= x;

        if(rowSum[i]==0)i++;
        if(colSum[j]==0)j++;
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