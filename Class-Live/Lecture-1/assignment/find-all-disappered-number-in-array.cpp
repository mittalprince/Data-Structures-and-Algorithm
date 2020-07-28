#include<iostream>
#include<vector>
using namespace std;

vector<int> findDisappearedNumbers(vector<int>& nums) {
    int n=nums.size();
    int i=0;
    while(i<n){
        if(nums[i] != nums[nums[i]-1]){
            swap(nums[i], nums[nums[i]-1]);
        }
        else{
            i++;
        }
    }
    vector<int>ans;
    for(int i=0; i<n; i++){
        if(nums[i] != i+1){
            ans.push_back(i+1);
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
    arr = findDisappearedNumbers(arr);
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return 0;
}