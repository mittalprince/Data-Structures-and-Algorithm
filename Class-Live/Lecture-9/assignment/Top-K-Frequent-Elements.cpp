#include<iostream>
#include<vector>
#include<map>
#include<unordered_map>
#include<queue>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);

vector<int> topKFrequent(vector<int>& nums, int k) {
    unordered_map<int,int>mp;
    for(int i=0;i<nums.size();i++) mp[nums[i]]++;

    priority_queue<pair<int,int> >pq;

    for(auto it=mp.begin();it!=mp.end();it++){
        pq.push({it->second,it->first});
    }
    vector<int>vec;
    int c =0;
    while(!pq.empty() && c!=k){
        pair<int,int> p = pq.top();
        pq.pop();
        c++;
        vec.push_back(p.second);
    }
    return vec;
}

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    
    return 0;
}