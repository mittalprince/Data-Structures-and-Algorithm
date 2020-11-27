//https://leetcode.com/problems/lru-cache/
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

class LRUCache {
public:
    list<int> l;
    map<int, int> m;
    int size;
    
    LRUCache(int capacity) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        
        l.clear();
        m.clear();
        size=capacity;
    }
    
    int get(int key) {
        if(m.find(key) == m.end()){
            return -1;
        }
        auto it = find(l.begin(), l.end(), key);
        if(it != l.end()){
            l.erase(it);
        }
        l.push_front(key);
        return m[key];
    }
    
    void put(int key, int value) {
        if(m.find(key) != m.end()){
            m[key]=value;
            auto it = find(l.begin(), l.end(), key);
            // if(it != l.end()){
                l.erase(it);
            // }
            l.push_front(key);
            return;
        }
        
        if(l.size()<size){
            m[key]=value;
            l.push_front(key);
        }
        else{
            map<int, int>::iterator it = m.find(l.back());
            if (it != m.end())
            {
                m.erase(it);
                l.pop_back();
                l.push_front(key);
                m[key] = value;
            }
        }
    }
};

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