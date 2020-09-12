// https://leetcode.com/problems/maximum-product-of-three-numbers/
#include<iostream>
#include<vector>
#include<climits>
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

int maximumProduct(vector<int>& nums) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int min1 =INT_MAX,min2=INT_MAX ,max1 = INT_MIN ,max2= INT_MIN ,max3= INT_MIN;

    int n=nums.size();

    for(int i=0; i<n; i++){
        if(nums[i]<min1){
            min2=min1;
            min1=nums[i];
        }
        else if(nums[i]<min2){
            min2=nums[i];
        }

        if(nums[i]>max1){
            max3=max2;
            max2=max1;
            max1=nums[i];
        }
        else if(nums[i]>max2){
            max3=max2;
            max2=nums[i];
        }
        else if(nums[i]>max3){
            max3=nums[i];
        }
    }
    return max(max1*max2*max3, min1*min2*max1);
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