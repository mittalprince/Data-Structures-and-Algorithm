#include<iostream>
#include<vector>
#include<queue>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);

int findKthLargest(vector<int>& nums, int k) {
    priority_queue<int, vector<int>, greater<int> >pq;

    if(nums.empty()) return -1;

    int i=0;
    while(k--){
        pq.push(nums[i++]);
    }

    for( ;i<nums.size(); i++){
        if(nums[i]>=pq.top()){
            pq.pop();
            pq.push(nums[i]);
        }
    }
    return pq.top();
}

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    
    return 0;
}