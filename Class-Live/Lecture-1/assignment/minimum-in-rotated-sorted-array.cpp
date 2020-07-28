#include<iostream>
#include<vector>
using namespace std;

int findMin(vector<int>& arr){
    int n=arr.size();
    if(n==1) return arr[0];
    int s=0, e=n-1;

    // no rotation
    if(arr[e] > arr[0]) return arr[0];   

    while(s<=e){
        int mid = (s+e)>>1;

        // check whether mid is greater is then next element,
        // if yes this is pivot element, return next elment;
        if(arr[mid]>arr[mid+1]) return arr[mid+1];

        // check whether mid is less than its prev
        // if yes, prev is pivot elemt, return mid
        if(arr[mid]<arr[mid-1]) return arr[mid];

        // if true, we have possibility to find next more large element than mid(may be mid is largest)
        // so to find next possible greater element move right
        if(arr[mid] > arr[0]){
            s=mid+1;
        }

        // i.e mid is less than first elemnt, so to largest element may be first or right to it but left of mid
        else e=mid-1;
    } 

    return arr[0];
}

int main()
{
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    cout << findMin(arr)<<endl;
    return 0;
}