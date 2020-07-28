#include<iostream>
#include<vector>
using namespace std;

int findMin(vector<int>&arr){
    int n=arr.size();
    int s=0, e=n-1;
    while(s<e){
        int mid=s+(e-s)/2;
        if(arr[e] < arr[mid]){
            s=mid+1;
        }
        else if(arr[e]>arr[mid]) e=mid;
        else e--;
    }
    return arr[s];
}

int main(){
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    cout<<findMin(arr)<<endl;
    return 0;
}