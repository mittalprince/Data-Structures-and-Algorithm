#include<iostream>
#include<vector>
#include<queue>
#include<unordered_map>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);

vector<int> rearrangeBarcodes(vector<int>& barcodes) {
    unordered_map<int, int>m;
    for(int i: barcodes){
        m[i]++;
    }

    priority_queue<pair<int, int>>pq;

    for(auto it: m){
        pq.push({it.second, it.first});
    }

    vector<int>ans;

    while(pq.size()>=2){
        auto t1=pq.top(); pq.pop();
        auto t2=pq.top(); pq.pop();

        // cout<<t1.second<<" "<<t1.first<<endl;
        // cout<<t2.second<<" "<<t2.first<<endl;

        // cout<<endl;
        ans.push_back(t1.second);
        ans.push_back(t2.second);

        if(t1.first>1) pq.push({t1.first-1, t1.second});
        if(t2.first>1) pq.push({t2.first-1, t2.second});
    }

    if(!pq.empty()){
        // cout<<"yes";
        ans.push_back(pq.top().second);
    }
    return ans;
}

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    
    return 0;
}