// https://leetcode.com/problems/find-k-pairs-with-smallest-sums/
#include<iostream>
#include<vector>
#include<map>
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

#define ppi pair<int, pair<int, int> >

vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n=nums1.size();
    int m=nums2.size();

    if(!n or !m)return {};

    map<pair<int, int>, bool>freq;

    auto cmp = [](const ppi a, const ppi b){
        return a.first>b.first;
    };

    priority_queue<ppi, vector<ppi>, decltype(cmp)>pq(cmp);
    freq[{0,0}]=1;
    pq.push({nums1[0]+nums2[0], {0,0}});

    vector<vector<int> >ans;

    while(ans.size()<k and ans.size()<(n*m)){
        ppi top = pq.top();
        pq.pop();


        int i=top.second.first, j=top.second.second;
        ans.push_back({nums1[i], nums2[j]});

        if(i+1<n and !freq[{i+1, j}]){
            pq.push({nums1[i+1]+nums2[j], {i+1, j}});
            freq[{i+1, j}]=true;
        }
        if(j+1<m and !freq[{i, j+1}]){
            pq.push({nums1[i]+nums2[j+1], {i, j+1}});
            freq[{i, j+1}]=true;
        }
    }
    return ans;
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