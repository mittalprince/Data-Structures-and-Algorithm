#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);

/*
Given an Array[] of N elements and a number K. ( 1 <= K <= N ) . 
Split the given array into K subarrays (they must cover all the elements). 
The maximum subarray sum achievable out of K subarrays formed, must be minimum possible. 
Find that possible subarray sum.
*/

bool check(int arr[], int n, int k, int mid){
    // mid ->maximum subarr sum (assume)
    int ct=0;
    int sum=0;

    for(int i=0; i<n; i++){
        if(arr[i] > mid){ 
            // If individual element is greater than maximum possible sum, then this mid can't be ans,
            // as the subarry formed using this element have sum greater then this mid, hence this mid is not optimal
            return false;
        }
        sum += arr[i];

        if(sum > mid){
            ct++;
            sum = arr[i];
        }
    }
    ct++;
    return (ct <= k);
}

int solve(int arr[], int n, int k){
    int start=1;
    int end = 0;

    for(int i=0; i<n; i++){
        end += arr[i];
    }

    int ans=0;
    // minimum sum can be 1 and the maximum sum can be the sum of all the elements.
    while(start<=end){
        int mid = (start+end)/2;
        if(check(arr, n, k, mid)){ // check if mid is maximum subarray sum possible.
            ans = mid;
            end=mid-1;
        }
        else start=mid+1;
    }
    return ans;
}
int main(){
    int n,k;
    cin>>n>>k;
    int arr[n];
    ip(arr, n);

    cout<<solve(arr, n, k)<<endl;
    return 0;
}