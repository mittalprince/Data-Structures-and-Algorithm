// https://leetcode.com/problems/find-peak-element/
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

int findPeakElement(vector<int>& nums) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n=nums.size();
    int s=0, e=n-1;
    while(s<e){
        int mid = (s+e)/2;
        if (nums[mid] > nums[mid+1])e=mid;
        else s=mid+1;
    }
    return s;
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