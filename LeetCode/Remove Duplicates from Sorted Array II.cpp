// https://leetcode.com/problems/remove-duplicates-from-sorted-array-ii/
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

int removeDuplicates(vector<int>& nums) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n=nums.size();
    if(n < 3)
        return n;

    int k=1;

    for(int i=1; i<n; i++){
        if(nums[i] != nums[k-1]){
            nums[k++]=nums[i];
        }
        else if(k<2 or nums[k-2] != nums[i]){
            nums[k++]=nums[i];
        }
    }

    return k;
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