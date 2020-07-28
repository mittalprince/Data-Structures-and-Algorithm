#include<iostream>
#include<vector>
using namespace std;

void reverse(vector<int>&arr, int start, int end){
    while(start<end){
        swap(arr[start], arr[end]);
        start++;
        end--;
    }
}

void rotate(vector<int>&arr, int k){
    int n=arr.size();
    k %= n;
    reverse(arr, 0, n-1);
    reverse(arr, 0, k-1);
    reverse(arr, k, n-1);
}

int main(){
    int n, k;
    cin>>n>>k;
    vector<int>arr(n, 0);
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    rotate(arr, k);
}
