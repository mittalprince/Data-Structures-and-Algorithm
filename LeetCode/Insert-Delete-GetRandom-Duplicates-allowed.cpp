#include<iostream>
#include<vector>
#include<unordered_map>
#include<unordered_set>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define debug(x) cout<<x<<"\n";
#define inf 1e9
#define INF 1e16
#define MOD 1000000007

class RandomizedCollection {
public:
    /** Initialize your data structure here. */
    unordered_map<int, unordered_set<int> >m;
    vector<int>arr;
    int n=0;
    
    RandomizedCollection() {
        
    }
    
    /** Inserts a value to the collection. Returns true if the collection did not already contain the specified element. */
    bool insert(int val) {
        bool ans=true;
        if(m.count(val)){
            ans= false;
        }
           
        m[val].insert(n++);
        arr.push_back(val);
        
        return ans;
    }
    
    /** Removes a value from the collection. Returns true if the collection contained the specified element. */
    bool remove(int val) {
        if(!m.count(val))return false;
        
        auto it = m[val].begin();
        int valPos = *it;
        
        m[val].erase(valPos);
        m[arr.back()].insert(valPos);
        m[arr.back()].erase(n-1);
        arr[valPos] = arr.back();
        arr.pop_back();
        
        n--;
        if(m[val].size()==0)m.erase(val);
        return true;
    }
    
    /** Get a random element from the collection. */
    int getRandom() {
        return arr[rand()%n];
    }
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection* obj = new RandomizedCollection();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */

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