#include<iostream>
#include<vector>
#include<queue>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);

/*
using Binary search
int kthSmallest(vector<vector<int>>& M, int k) {
    int n = M.size();

    int l = M[0][0];
    int r = M[n-1][n-1];

    int mid;
    while(l < r){
        mid = (l+r)>>1;
        int rem = 0;

        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(M[i][j] <= mid){
                    rem++;
                }
                else{
                    break;
                }
            }
        }

        if( rem < k){
            l = mid+1;
        }
        else{
            r = mid;;
        }
    }

    return l;

}
*/

int kthSmallest(vector<vector<int>>& matrix, int k) {
    priority_queue<int>pq;

    int n=matrix.size();
    if(n==0) return -1;
    int m=matrix[0].size();

    int i=0, j=0;

    while(k--){
        pq.push(matrix[i][j]);
        j++;
        if(j==m){
            j=0;i++;
        }
    }

     while( i<n){
        if(matrix[i][j] < pq.top()){
            pq.pop();
            pq.push(matrix[i][j]);
        }

        j++;
        if(j== n){
            j=0;
            i++;
        }
    }
    return pq.top();
}

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    
    return 0;
}