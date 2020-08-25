// https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix/
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

int kthSmallest(vector<vector<int>>& matrix, int k) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n=matrix.size();

    int l = matrix[0][0];
    int r = matrix[n-1][n-1];

    int mid;
    while(l<r){
        mid = (l+r)/2;
        int rem=0;

        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(matrix[i][j]<=mid){
                    rem++;
                }        
                else break;
            }
        }

        if(rem<k){
            l=mid+1;
        }
        else{
            r=mid;
        }
    }
    return l;
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