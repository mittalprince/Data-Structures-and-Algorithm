#include<iostream>
#include<vector>
#include<map>
#include<queue>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define ppi pair<int, pair<int, int>>

class comp{
    public:
    bool operator()(ppi &a, ppi &b){
        return a.first>b.first;
    }
};

vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
    vector<vector<int>>ans;

    int N=nums1.size(), M=nums2.size();
    if(N==0 || M==0){
        return ans;
    }

    map<pair<int, int>, bool>m;
    priority_queue<ppi, vector<ppi>, comp>pq;

    pq.push({nums1[0]+nums2[0], {0,0}});
    m[{0,0}]=true;

    while(ans.size()<k && ans.size() <(N*M)){
        auto top = pq.top();
        pq.pop();

        ans.push_back({nums1[top.second.first], nums2[top.second.second]});

        int i=top.second.first, j=top.second.second;

        if(i+1 < N && !m[{i+1, j}]){
            pq.push({nums1[i+1]+nums2[j], {i+1, j}});
            m[{i+1, j}]=true;   
        }

        if(j+1<M &&!m[{i, j+1}]){
            pq.push({nums1[i]+nums2[j+1], {i, j+1}});
            m[{i, j+1}]=true;
        }
    }
    return ans;
}

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    
    return 0;
}