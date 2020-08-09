// https://leetcode.com/problems/maximum-number-of-non-overlapping-subarrays-with-sum-equals-target/
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

int maxNonOverlapping(vector<int>& nums, int target) {
    set<int> s;
    s.insert(0);
    int ps=0, ans=0;
    for(int a : nums) {
        ps+=a;
        if(s.find(ps-target)!=s.end()) {
            ++ans;
            s.clear();
        }
        s.insert(ps);
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