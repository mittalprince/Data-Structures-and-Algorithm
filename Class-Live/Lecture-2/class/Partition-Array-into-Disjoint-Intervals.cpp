#include<iostream>
#include<vector>
#include<climits>
using namespace std;

int partitionDisjoint(vector<int>&arr){
    int n=arr.size();
    int left_max=arr[0], curr_max=arr[0], len=0;
    for(int i=1; i<n; i++){
        curr_max = max(curr_max, arr[i]);
        if(arr[i] < left_max){
            len=i;
            left_max = curr_max;
        }
    }    
    return len+1;
}

int main()
{
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    cout<<partitionDisjoint(arr)<<endl;
    return 0;
}