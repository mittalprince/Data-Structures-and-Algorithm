// https://leetcode.com/problems/find-k-th-smallest-pair-distance/
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

bool check(vector<int>&arr, int mid, int k){
    int ct=0;
    int l=0, r=1, n=arr.size();
    while(r<n){
        if(arr[r]-arr[l]<=mid){
            ct += (r-l);
            r++;
        }
        else l++;
        if(l==r)r++;
    }
    return ct>=k;
}

int smallestDistancePair(vector<int>& nums, int k) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    sort(nums.begin(), nums.end());
    int n=nums.size();

    int l=0, r=nums[n-1]-nums[0];
    int ans=-1;

    while(l<r){
        int mid = (l+r)/2;
        if(check(nums, mid, k)){
            r=mid;
        }
        else{
            l=mid+1;
        }
    }
    return l;
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