// https://leetcode.com/problems/find-a-value-of-a-mysterious-function-closest-to-target/
#include<iostream>
#include<vector>
#include<unordered_set>
#include<climits>
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

int closestToTarget(vector<int>& arr, int k) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int ans = INT_MAX; 
    unordered_set<int>s;
    for(int i: arr){
        unordered_set<int>ns;
        for(int j: s){
            ns.insert(i&j);
        }
        ns.insert(i);
        for(int j: ns){
            ans = min(ans, abs(k-j));
        }
        s=ns;
    }
    return ans; 
}

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