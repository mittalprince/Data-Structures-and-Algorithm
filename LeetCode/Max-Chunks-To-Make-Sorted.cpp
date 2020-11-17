//https://leetcode.com/problems/max-chunks-to-make-sorted/
#include<iostream>
#include<vector>
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

int maxChunksToSorted(vector<int>& arr) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int ans=0;
    int n=arr.size();
    int curr_max = INT_MIN;

    for(int i=0; i<n; i++){
        curr_max = max(curr_max, arr[i]);
        ans += curr_max==i;
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