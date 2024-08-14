// https://leetcode.com/problems/merge-sorted-array/
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

void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int i=m-1, j=n-1;
    int k=m + n - 1;
    while(i>=0 && j>=0){
        if(nums1[i]<nums2[j]){
            nums1[k] = nums2[j];
            j--;
        }
        else{
            nums1[k] = nums1[i];
            i--;
        }
        k--;
    }

    while(j>=0 && k>=0){
        nums1[k]=nums2[j];
        j--;
        k--;
    }
    while(i>=0 && k>=0){
        nums1[k]=nums1[i];
        i--;
        k--;
    }
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