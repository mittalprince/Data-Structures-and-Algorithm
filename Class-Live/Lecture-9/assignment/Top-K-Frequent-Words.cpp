#include<iostream>
#include<vector>
#include<queue>
#include<unordered_map>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);

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

    cout<<pq.top().second<<endl;
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
    int n;
    cin>>n;
    vector<int> arr(n);
    
    return 0;
}