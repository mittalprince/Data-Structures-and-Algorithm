#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);

int maxSubArray(vector<int>&arr){
    int n=arr.size();
    int max_sum=INT_MIN, cs=0;
    for(int i=0; i<n; i++){
        cs += arr[i];
        max_sum = max(max_sum, cs);
        if(cs<0) cs=0;
    }    
    return max_sum;
}

int main()
{
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0; i<n; i++{
        cin>>arr[i];
    }
    cout<<maxSubArray(arr)<<endl;
    return 0;
}