// https://leetcode.com/problems/top-k-frequent-elements/
#include<iostream>
#include<vector>
#include<unordered_map>
#include<queue>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define ip1(arr, n) for(int i=1; i<=n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define debug(x) cout<<x<<"\n";
#define inf 1e9
#define INF 1e16
#define MOD 1000000007

class comp{
    public:
    bool operator()(const pair<int, int>a, const pair<int, int>b){
        return a.second>b.second;
    }
};
vector<int> topKFrequent(vector<int>& nums, int k){
    unordered_map<int, int>m;
    for(int i: nums){
        m[i]++;
    }
    typedef pair<int, int> pi;
    priority_queue<pi, vector<pi>, comp> pq;
    for(auto it: m){
        pq.push({it.first, it.second});
        if(pq.size() > k) pq.pop();
    }
    vector<int>ans;
    while(!pq.empty()){
        pi p = pq.top();
        pq.pop();
        ans.push_back(p.first);
    }
    return ans;
}
int main(){

/*
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
*/

    int n;
    cin>>n;
    vector<int> arr(n);
    
    return 0;
}