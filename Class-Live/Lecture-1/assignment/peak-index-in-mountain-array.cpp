#include<iostream>
#include<vector>
using namespace std;

int peakIndexInMountainArray(vector<int>& arr){
    int n=arr.size();
    int s=0, e=n-1;
    while(s<e){
        int mid = (s+e)/2;
        if(arr[mid-1]<arr[mid] && arr[mid] > arr[mid+1]) return mid;
        if(arr[mid]<arr[mid+1]) s=mid+1;
        else e=mid;
    }
    return s;
}
int main(){
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0; i<n; i++{
        cin>>arr[i];
    }
    cout<<peakIndexInMountainArray(arr)<<endl;
    return 0;
}