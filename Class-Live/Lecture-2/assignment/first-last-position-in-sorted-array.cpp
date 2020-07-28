#include<iostream>
#include<vector>
using namespace std;

vector<int> searchRange(vector<int>&arr, int target){
    int n=arr.size();
    int s=0, e=n-1;
    int low=-1, high=-1;
    while(s<=e){
        int mid = s+(e-s)/2;
        if(arr[mid] >= target){
            low=mid;
            e=mid-1;
        }
        else s=mid+1;
    }
    if(low == -1 || arr[low] != target) return {-1,-1};
    s=0, e=n-1;

    while(s<=e){
        int mid = s+(e-s)/2;
        if(arr[mid]>target){
            e=mid-1;
        }
        else{
            s=mid+1;
            high = mid;
        }
    }
    return {low,high};
}

int main()
{
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    int target;
    cin>>target;
    vector<int> ans = searchRange(arr, target);
    return 0;
}