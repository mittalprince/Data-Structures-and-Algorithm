// https://www.interviewbit.com/problems/matrix-median/
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
 
// Variant -> Find the kth smallest element in 2D matrix with row sorted.
int findMedian(vector<vector<int> > &A) {
    int n = A.size();
    int m = A[0].size();
    
    int k = ((n*m)+1)/2;
    
    int l=A[0][0];
    int r = A[n-1][m-1];
    
    for(int i = 0; i < n; i ++) {
        if(A[i][0] < l) l = A[i][0];
        if(A[i][m-1] > r) r = A[i][m-1];
    }
    
    while(l<r){
        int mid = (l+r)/2;
        int rem=0;
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(A[i][j]<=mid)rem++;
                else break;
            }
        }
        
        if(rem<k){
            l=mid+1;
        }
        else r=mid;
    }
    
    return r;
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