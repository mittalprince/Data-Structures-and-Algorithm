// https://leetcode.com/problems/binary-search/
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

int search(vector<int>& nums, int target) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n=nums.size();
    int ans=-1;

    int l=0, r=n-1;
    while(l<=r){
        int mid = (l+r)/2;
        if(nums[mid]==target){
            ans=mid;
            break;
        }
        if(nums[mid]<target){
            l=mid+1;
        }
        else r=mid-1;
    }

    return ans;
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