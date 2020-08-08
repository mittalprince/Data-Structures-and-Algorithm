// https://leetcode.com/problems/sort-an-array/
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

void quickSort(vector<int>&arr, int start, int end){
    if(start >= end) return ;
    int left=start, right=end;
    int pivot = arr[(start+end)/2];

    while(start<=end){
        while(start<=end && arr[start]<pivot){
            start++;
        }
        while(start<=end && arr[end]>pivot){
            end--;
        }

        if(start<=end){
            swap(arr[start], arr[end]);
            start++;
            end--;
        }
    }

    quickSort(arr, start, right);
    quickSort(arr, left, end);
}

vector<int> sortArray(vector<int>& nums) {
    // mergeSort(nums, 0, nums.size()-1);
    // qs(nums, 0, nums.size()-1);
    quickSort(nums, 0, nums.size()-1);
    return nums;
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