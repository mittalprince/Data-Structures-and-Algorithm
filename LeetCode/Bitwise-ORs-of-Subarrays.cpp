#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define MOD 1000000007
/*
We have an array A of non-negative integers.
For every (contiguous) subarray B = [A[i], A[i+1], ..., A[j]] (with i <= j), 
we take the bitwise OR of all the elements in B, obtaining a result A[i] | A[i+1] | ... | A[j].
Return the number of possible results.  (Results that occur more than once are only counted once in the final answer.)
*/

int subarrayBitwiseORs(vector<int>& A) {
    unordered_set<int> res;
    unordered_set<int> cur;
    unordered_set<int> cur2;
    for (int a:A){
        cur2 = {a};
        for (int c:cur){
            cur2.insert(c | a);
        }
        cur = cur2;
        res.insert(cur.begin(), cur.end());
    }
    return res.size();
}

int main(){

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    int n;
    cin>>n;
    vector<int> arr(n);
    ip(arr, n);
    cout<<subarrayBitwiseORs(arr)<<endl;
    return 0;
}