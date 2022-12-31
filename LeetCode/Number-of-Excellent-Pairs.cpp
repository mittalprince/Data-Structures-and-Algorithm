// https://leetcode.com/problems/number-of-excellent-pairs/
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

long long countExcellentPairs(vector<int>& nums, int k) {
    // https://leetcode.com/problems/number-of-excellent-pairs/discuss/2324984/JavaC%2B%2BPython-Inclusion-Exclusion-Principle
    long long cnt[30] = {}, res = 0;
    set<int>s (nums.begin(), nums.end());
    for(int i: s) {
        cnt[__builtin_popcount(i)]++;
    }
    for(int i=1; i<30; i++){
        for(int j=1;j<30; j++){
            if (i+j>=k) res += cnt[i]*cnt[j];  
        }
    }
    return res;
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