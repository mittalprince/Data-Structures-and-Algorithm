#include<iostream>
#include<vector>
using namespace std;

bool checkPossibility(vector<int>& nums) {
    int n=nums.size();
    int opt1=0, opt2=0; 
    int prev = nums[0];
    for(int i=1; i<n; i++){
        prev = max(prev, nums[i]);
        if(nums[i] < prev) opt1++;
    }
    prev = nums[n-1];
    for(int i=n-2; i>=0; i--){
        prev = min(prev, nums[i]);
        if(nums[i]>prev) opt2++;
    }
    
    if(opt1 > 1 && opt2 >1) return false;
    return true;
}

int main(){
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    (checkPossibility(arr))?cout<<"true\n":cout<<"false\n";
    return 0;
}