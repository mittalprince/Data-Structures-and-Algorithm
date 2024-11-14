// https://leetcode.com/problems/nested-list-weight-sum-ii/
#include<iostream>
#include<vector>
#include<map>
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

/*
For this problem you are given a list of NestedIntegers, a data structure that is loosely defined as follows, a nested integer is either an integer or a list of integers. The question goes as follows given a list of NestedIntegers find the nested list weight sum which is the sum of the integers in the list weighted by depth such that the integers in a list of integers have 1 less in weight than the ones outside. Complete description in the problem link.
For example in [1, [4, [6]]] 1 has weight 3, 4 has weight 2 and 6 has weight 1. Their sum is 17.
*/
// N -> nodes count, H -> height
// TC -> O(n)
// SC -> O(H) + O(H) -> first one for height h recursive call stack and second one for map(max keys will be max hright of tree)
void solve(vector<NestedInteger> &nestedList, map<int, int>&m, int depth){
    for (NestedInteger it: nestedList){
        if (it.isInteger()){
            m[depth] += it.getInteger();
        } else{
            solve(nestedList, m, depth+1);
        }
    }
}

int depthSumInverse(vector<NestedInteger> &nestedList){
    map<int, int>m;
    solve(nestedList, m, 1);
    int ans = 0;
    int maxDepth = *m.rbegin().first;
    for(auto it: m){
        ans += (maxDepth-it.first+1)*it.second;
    }
    return ans;
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