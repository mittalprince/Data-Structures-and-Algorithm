#include<iostream>
#include<vector>
using namespace std;

vector<int> findDuplicates(vector<int>arr){
    int n=arr.size();
    vector<int>ans;
    for(int i=0; i<n; i++){
        int idx = abs(arr[i])-1;
        if(arr[idx]<0){
            ans.push_back(abs(arr[i]));
        }
        else{
            arr[idx] *= -1;
        }
    }    
    return ans;
}

int main(){
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    vector<int>ans = findDuplicates(arr);
    for(int i: ans){
        cout<<i<<" ";
    }
    cout<<endl;
    return 0;
}