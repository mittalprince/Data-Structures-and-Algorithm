#include<iostream>
#include<vector>
using namespace std;

int minPatches(vector<int>&arr, int N){
    int n=arr.size();
    int add=0;
    long long missing=1;
    int i=0;
    while(missing<=N){
        if(i<n && missing >= arr[i]){
            missing += arr[i];
        }
        else{
            add++;
            missing += missing;
        }
    }
    return add;
}

int main(){
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    int N;
    cin>>N;
    cout<<minPatches(arr, N)<<endl;
    return 0;
}