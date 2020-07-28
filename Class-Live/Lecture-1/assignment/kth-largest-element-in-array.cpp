#include<iostream>
#include<queue>
using namespace std;

int findKthLargest(vector<int>& nums, int k){
    int n=nums.size();
    priority_queue<int, vector<int>, greater<int> >pq;
    
    int i=0;
    while(k--){
        pq.push(nums[i]);
        i++;
    }
    for(; i<n; i++){
        if(pq.top()<nums[i]){
            pq.pop();
            pq.push(nums[i]);
        }
    }
    
    return pq.top();
}

int main(){
    int n,k;
    cin>>n>>k;
    vector<int>arr(n);
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    cout<<findKthLargest(arr, k)<<endl;
    return 0;
}