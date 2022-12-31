// https://leetcode.com/problems/shortest-impossible-sequence-of-rolls/
#include<iostream>
#include<vector>
#include<set>
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

int shortestSequence(vector<int>& rolls, int k) {
    // https://leetcode.com/problems/shortest-impossible-sequence-of-rolls/discuss/2323263/Easy-To-Understand-oror-Java-Solution-oror-Linear-Traversal-oror-With-Explanation-oror-With-Question-Explain
    int ans=1;
    set<int>s;

    for(int i:rolls){
        s.insert(i);
        if (s.size()==k){
            s.clear();
            ans++;
        }
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