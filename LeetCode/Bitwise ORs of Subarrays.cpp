// https://leetcode.com/problems/bitwise-ors-of-subarrays/
#include<iostream>
#include<vector>
#include<unordered_set>
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

int subarrayBitwiseORs(vector<int>& A) {
    unordered_set<int> res;
    unordered_set<int> cur;
    unordered_set<int> cur2;
    for (int a:A){
        cur2 = {a};
        // In each time, we add a new number to each array of the previous line.
        for (int c:cur){
            cur2.insert(c | a);
        }
        cur = cur2;
        res.insert(cur.begin(), cur.end());
    }
    return res.size();
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