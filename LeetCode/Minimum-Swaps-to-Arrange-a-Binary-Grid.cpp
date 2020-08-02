// https://leetcode.com/problems/minimum-swaps-to-arrange-a-binary-grid/
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

int minSwaps(vector<vector<int>>& grid) {
    int n=grid.size();
    vector<int>A;

    for(int i=0; i<n; i++){
        int ct=0;
        for(int j=n-1; j>=0; j--){
            if(grid[i][j]==0)ct++;
            else break;
        }
        A.push_back(ct);
    }

    int ans=0;
    for(int i=0; i<n; i++){
        int req_zero = n-i-1;
        int j=i;
        while(j<n and A[j]<req_zero)j++;
        if(j>=n)return -1;

        for(int k=j; k>i; k--){
            ans++;
            swap(A[k], A[k-1]);
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