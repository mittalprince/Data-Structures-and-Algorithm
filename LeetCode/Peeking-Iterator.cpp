//https://leetcode.com/problems/peeking-iterator/
#include<iostream>
#include<vector>
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

class PeekingIterator : public Iterator {
    bool has_next = false;
    int next_val = -1;
public:
	PeekingIterator(const vector<int>& nums) : Iterator(nums) {
	    ios_base::sync_with_stdio(false);
        cin.tie(NULL);
	    has_next = Iterator::hasNext();
        if(has_next){
            next_val = Iterator::next();
        }
	}
	
    // Returns the next element in the iteration without advancing the iterator.
	int peek() {
        return next_val;
	}
	
	// hasNext() and next() should behave the same as in the Iterator interface.
	// Override them if needed.
	int next() {
	    int ans = next_val;
        has_next = Iterator::hasNext();
        if(has_next){
            next_val = Iterator::next();
        }
        return ans;
	}
	
	bool hasNext() const {
	    return has_next;
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