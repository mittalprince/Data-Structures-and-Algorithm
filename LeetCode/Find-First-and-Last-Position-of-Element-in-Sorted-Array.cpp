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

int lower_bound(vector<int>&arr, int target){
    int ans=-1;
    int n= arr.size();
    int s=0, e=n-1;

    while(s<=e){
        int mid = (s+e)/2;
        if(arr[mid] == target){
            ans=mid;
            e=mid-1;
        }
        else if(arr[mid]>target)e=mid-1;
        else s=mid+1;
    }
    return ans;
}

int upper_bound(vector<int>&arr, int target){
    int ans=-1;
    int n= arr.size();
    int s=0, e=n-1;

    while(s<=e){
        int mid = (s+e)/2;
        if(arr[mid] == target){
            ans=mid;
            s=mid+1;
        }
        else if(arr[mid]>target)e=mid-1;
        else s=mid+1;
    }
    return ans;
}

vector<int> searchRange(vector<int>& nums, int target) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int l = lower_bound(nums,target);
    int u = upper_bound(nums,target);
    return {l,u};
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