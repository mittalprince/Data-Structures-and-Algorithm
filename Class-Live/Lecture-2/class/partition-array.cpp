#include<iostream>
#include<vector>
using namespace std;

int arrayPairSum(vector<int>&arr){
    int n=arr.size();
    vector<int> freq(20001, 0);
    for(int i=0; i<n; i++){
        freq[arr[i]+10000]++;
    }
    int sum=0, pick=0;
    // int lena_hai=0;
    // for(int i=0; i<freq.size(); i++){
    //     sum += ((freq[i]+1-lena_hai)/2)*(i-10000);
    //     lena_hai = (2+freq[i]-lena_hai)%2;  
    // }
    for(int i=0; i<freq.size(); i++){
        if(freq[i]>0){
            for(int j=0; j<freq[i]; j++){
                pick++;
                if(pick&1) sum += (i-10000);
            }
        }
    }
    return sum;
}

int main(){
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    cout<<arrayPairSum(arr)<<endl;
    return 0;
} 