// https://leetcode.com/problems/circular-array-loop/
#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define MOD 1000000007

int next(vector<int>&arr, int x){
    return (x+arr[x]+arr.size())%arr.size();
}

bool circularArrayLoop(vector<int>& nums){
    int n=nums.size();

    for(int i=0; i<n; i++){// check at each until we get a cycle
        int slw=i, fst=i;

        while(nums[i]*nums[next(nums, slw)]>0 && nums[i]*nums[next(nums, fst)]>0 && nums[i]*nums[next(nums, next(nums, fst))] > 0){
            slw = next(nums, slw);
            fst = next(nums, next(nums, fst));

            if(slw == fst){
                if(slw == next(nums, slw)){
                    break; // check if we get a cycle of 1 len
                }
                return true;
            }
        }
        
        // if we dont get cycle for a particular i then we make this path into 0
        // as if we jump or reach at any pos of this path we can't get cycle
        slw = i;
        int x = nums[slw];
        while(x*nums[slw]>0){
            int y = next(nums, slw);
            nums[slw] = 0;
            slw = y;
        }
    }

    return false;
}

int main(){

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    int n;
    cin>>n;
    vector<int> arr(n);
    
    return 0;
}