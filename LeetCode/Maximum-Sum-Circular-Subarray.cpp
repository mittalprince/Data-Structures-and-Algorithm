#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);

// option 1. normal kadane
// option 2. array-sum - (-max subarray sum of inverted array)
int kadane(vector<int>&A){
    int n=A.size();
    int curr=0, max_sum=INT_MIN;

    for(int i=0; i<n; i++){
        curr += A[i];
        if(max_sum<curr){
            max_sum=curr;
        }
        if(curr<0) curr=0;
    }
    return max_sum;
}

int maxSubarraySumCircular(vector<int>& A) {
    int n=A.size();
    int ans = kadane(A);

    int max_circular=0, neg_elmt=0;
    for(int i=0; i<n; i++){
        max_circular += A[i];
        if(A[i]<0) neg_elmt++;
        A[i] = -A[i];
    }

    if(neg_elmt == n) return ans; 
    max_circular += kadane(A);

    return max(ans, max_circular);
}
int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    
    return 0;
}