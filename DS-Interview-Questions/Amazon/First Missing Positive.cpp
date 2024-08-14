// https://leetcode.com/problems/first-missing-positive/
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

int firstMissingPositive(vector<int>& nums){
    int n = nums.size();
    int i=0;
    while(i<n){
        if(nums[i]<=0 || nums[i]>n || nums[i]==(i+1)){
            i++;
            continue;
        }
        if(nums[i] != nums[nums[i]-1]){
            swap(nums[i], nums[nums[i]-1]);
        } else i++;
    }
    for(int i=0; i<n; i++){
        if(nums[i] != i+1) return i+1;
    }
    return n+1;
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