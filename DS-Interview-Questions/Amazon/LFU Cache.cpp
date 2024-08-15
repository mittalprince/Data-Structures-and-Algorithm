// https://leetcode.com/problems/lfu-cache/
#include<iostream>
#include<vector>
#include<list>
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

class LFUCache {
    int curr_size;
    int capacity;
    int minFreq;
    unordered_map<int, pair<int, int>>m; // key to {value, freq}
    unordered_map<int, list<int>>fm; // freq to key list;
    unordered_map<int, list<int>::iterator> mIter; // key to list iterator;

public:
    LFUCache(int capacity) {
        this->capacity = capacity;
        this->curr_size = 0;
    }
    
    int get(int key) {
        if(m.count(key)){
            fm[m[key].second].erase(mIter[key]);
            m[key].second++;
            fm[m[key].second].push_back(key);
            mIter[key] = --fm[m[key].second].end();

            if (fm[minFreq].size()==0)minFreq++;
            return m[key].first;
        }
        return -1;
    }
    
    void put(int key, int value) {
        int storeVal = get(key);
        if(storeVal != -1){
            m[key].first = value;
            return;
        }
        if(curr_size >= capacity){
            m.erase(fm[minFreq].front());
            mIter.erase(fm[minFreq].front());
            fm[minFreq].pop_front();
            curr_size--;
        }
        m[key] = {value, 1};
        minFreq = 1;
        fm[minFreq].push_back(key);
        curr_size++;
        mIter[key] = --fm[minFreq].end();
    }
};

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