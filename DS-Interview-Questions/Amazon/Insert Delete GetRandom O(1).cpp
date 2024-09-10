// https://leetcode.com/problems/insert-delete-getrandom-o1/
#include<iostream>
#include<vector>
#include<unordeered_map>
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

class RandomizedSet {
public:
    /** Initialize your data structure here. */
    unordered_map<int, int>m;
    vector<int>arr;
    int n=0;
    
    RandomizedSet() {
        
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if(m.count(val)){
            return false;
        }
        m[val]=n++;
        arr.push_back(val);
        return true;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if(!m.count(val))return false;
        
        int idx = m[val];
        m[arr.back()]=idx;
        arr[idx] = arr.back();
        arr.pop_back();
        m.erase(val);
        n--;
        return true;
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        return arr[rand()%n];
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