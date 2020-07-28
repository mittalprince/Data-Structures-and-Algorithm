// http://buttercola.blogspot.com/2015/08/leetcode.html
#include<iostream>
#include<vector>
#include<algorithm>
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

/*
If A[i] + A[j] + A[k] < target, which means the numbers between j and k are all less than target, because the array is sorted. Then we move the j pointer forward.
If it's less then the target, then that means it needs to be accounted for when you update the result count. If you don't, the algorithm won't hit those cases.
*/

int threeSumSmaller(vector<int>&nums, int target){
    if(nums.empty() or nums.size()<3){
        return 0;
    }

    int result=0;
    sort(nums.begin(), nums.end());

    for(int i=0; i<nums.size()-1; i++){
        int j=i+1;
        int k=nums.size()-1;
        while(j<k){
            if(nums[i]+nums[j]+nums[k]<target){
                result += (k-j); // as if we fix i,j then we have atmost (k-j) numbers avialble such that they make triplets which have sum < target
                j++;
            }
            else k--;
        }
    }
    return result;
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