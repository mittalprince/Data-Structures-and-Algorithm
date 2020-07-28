#include<iostream>
#include<vector>
#include<stack>
#include<map>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);

vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
    map<int, int>m;
    stack<int> s;
    for(int i=nums2.size()-1; i>=0; i--){
        while(!s.empty() && s.top() <= nums2[i]) s.pop();
        m[nums2[i]] = s.empty()?-1:s.top();
        s.push(nums2[i]);
    }

    for(int i=0; i<nums1.size(); i++){
        nums1[i] = m[nums1[i]];
    }
    return nums1;
}

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    
    return 0;
}