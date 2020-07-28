#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);

bool canJump(vector<int>& nums) {
    int n=nums.size()-1;
    int lastPos = n;

    for(int i=n-1; i>=0; i--){
        if(i+nums[i]>=lastPos){
            lastPos=i;
        }
    }

    return lastPos==0;
}

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    
    return 0;
}