#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);

int firstMissingPositive(vector<int>& nums) {
    int i=0, n=nums.size();

    while(i<n){
        if(nums[i]<=0 || nums[i]>n || nums[i]==(i+1)){
            i++;
            continue;
        }
        else{
            if(nums[i] != nums[nums[i]-1]){
                swap(nums[i], nums[nums[i]-1]);
            }
            else i++;
        }
    }

    for(int i=0; i<n; i++){
        if(nums[i] != i+1) return i+1;
    }
    return n+1;
}

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    
    return 0;
}