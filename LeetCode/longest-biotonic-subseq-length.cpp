#include<iostream>
using namespace std;

int lbs(int arr[], int n){
    int lis[n], lds[n];

    for(int i=0; i<n; i++){
        lis[i]=1;
        lds[i]=1;
    }
    for(int i=1; i<n; i++){
        for(int j=0; j<i; j++){
            if(arr[i]>arr[j] && lis[i]<lis[j]+1){
                lis[i]=lis[j]+1;
            }
        }
    }

    for(int i=n-2; i>=0; i--){
        for(int j=n-1; j>i; j--){
            if(arr[i]>arr[j] && lds[i]<lds[j]+1){
                lds[i]=lds[j]+1;
            }
        }
    }
    int ans=lis[0]+lds[0]-1;
    for(int i=1; i<n; i++){
        ans = max(ans, lds[i]+lis[i]-1);
    }
    return ans;
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    cout<<lbs(arr, n)<<endl;
    return 0;
}