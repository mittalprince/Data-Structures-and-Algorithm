// https://leetcode.com/problems/find-in-mountain-array/
#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define MOD 1000000007

class MountainArray{
    public : 
    int get(int index);
    int length();
};

int pivot(MountainArray &mountainArr, int n){
    int start=0, end=n-1;

    while(start<end){
        int mid = (start+end)/2;
        if(mountainArr.get(mid) < mountainArr.get(mid+1)){
            start=mid+1;
        }
        else end=mid;
    }

    return start;
}

int searchInc(MountainArray &mountainArr, int start, int end, int target){
    while(start<=end){
        int mid = (start+end)/2;
        int val = mountainArr.get(mid);
        if(val == target){
            return mid;
        }
        else if(val<target) start=mid+1;
        else end=mid-1;

    }
    return -1;
}

int searchDec(MountainArray &mountainArr, int start, int end, int target){
    while(start<=end){
        int mid = (start+end)/2;
        int val = mountainArr.get(mid);
        if(val == target){
            return mid;
        }
        else if(val>target) start=mid+1;
        else end=mid-1;

    }
    return -1;
}

int findInMountainArray(int target, MountainArray &mountainArr) {
    int n=mountainArr.length();
    int k = pivot(mountainArr, n);
    int ans = searchInc(mountainArr, 0, k-1, target);
    if(ans == -1){
        ans = searchDec(mountainArr, k, n-1, target);
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