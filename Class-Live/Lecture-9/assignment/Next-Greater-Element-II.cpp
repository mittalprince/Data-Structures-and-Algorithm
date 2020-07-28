#include<iostream>
#include<vector>
#include<stack>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);

vector<int> nextGreaterElements(vector<int>& nums) {
    int n=nums.size();
    if(n==0) return {};

    vector<int>ans(n, 0);
    stack<int>s;

    for(int i=2*n-1; i>=0; i--){
        while(!s.empty() && s.top()<= nums[i%n]) s.pop();
        ans[i%n] = s.empty()?-1:s.top();
        s.push(nums[i%n]);
    }

    return ans;
}

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    
    return 0;
}