// https://leetcode.com/problems/maximum-matrix-sum/
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

long long maxMatrixSum(vector<vector<int>>& a) {
    long long neg_cnt = 0, ans = 0, size = a.size(), minn = 1000000;
    for (int i = 0; i < size; ++i)
        for (int j = 0; j < size; ++j) {
            ans += abs(a[i][j]);
            if (a[i][j] < 0)
                neg_cnt++;
            minn = minn < abs(a[i][j])? minn: abs(a[i][j]);
        }
    if (neg_cnt % 2 == 0)
        return ans;
    else 
        return ans - 2*minn;
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