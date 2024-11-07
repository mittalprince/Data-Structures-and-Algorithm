// https://leetcode.com/problems/find-if-array-can-be-sorted/
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

bool canSortArray(vector<int>& nums) {
    int n = nums.size();
    int pmax = 0, cmax = 0, cmin = 0;
    int pcnt = 0;
    for(int i: nums){
        int ct = __builtin_popcount(i);
        if(ct == pcnt){
            cmin = min(cmin, i);
            cmax = max(cmax, i);
        } else if(cmin < pmax)return false;
        else {
            pmax = cmax;
            cmin = cmax = i;
            pcnt = ct;
        }
    }
    return cmin >= pmax;
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