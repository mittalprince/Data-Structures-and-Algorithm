//https://leetcode.com/problems/top-k-frequent-words/
#include<iostream>
#include<queue>
#include<vector>
#include<unordered_map>
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

    bool operator()(pair<int, string>&a, pair<int, string>&b){
        if(a.first == b.first){
            return a.second<b.second;
        }
        return a.first>b.first;
    }
};
vector<string> topKFrequent(vector<string>& words, int k) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    unordered_map<string, int>m;

    for(string i: words){
        m[i]++;
    }

    priority_queue<pair<int, string>, vector<pair<int, string>>, comp>pq;

    unordered_map<string, int>::iterator it=m.begin();

    while(k-- && it != m.end()){
        pq.push({it->second, it->first});
        it++;
    }

    // cout<<pq.top().second<<endl;
    while(it != m.end()){
        if(it->second > pq.top().first || (it->second == pq.top().first && it->first < pq.top().second)){
            pq.pop();
            pq.push({it->second, it->first});
        }
        it++;
    }
    vector<string>ans(pq.size());
    int idx = pq.size()-1;
    while(!pq.empty()){
        pair<int, string>top= pq.top();
        pq.pop();
        ans[idx--] = top.second;
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