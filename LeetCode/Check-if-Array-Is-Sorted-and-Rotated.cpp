//https://leetcode.com/problems/check-if-array-is-sorted-and-rotated/
#include<iostream>
#include<vector>
#include<algorithm>
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

bool check(vector<int>& nums) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector<int> b = nums;
    sort(nums.begin(), nums.end());
    for(int i=1; i<=nums.size(); i++){
        rotate(b.begin(), b.begin()+1, b.end());
        if(nums == b)return 1;
    }
    return 0;
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