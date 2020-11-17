//https://leetcode.com/problems/max-chunks-to-make-sorted-ii/
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

int maxChunksToSorted(vector<int>& arr) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int>t(arr);
    sort(t.begin(), t.end());

    int n=arr.size();
    long long a=0, b=0, ans=0;
    for(int i=0; i<n; i++){
        a += arr[i];
        b += t[i];
        ans += a==b;
    }
    return ans;
}

int maxChunksToSorted(vector<int>& arr) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n=arr.size();
    vector<int>left(n), right(n);
    left[0]=arr[0];
    right[n-1] = arr[n-1];

    for(int i=1; i<n; i++){
        left[i] = max(left[i-1], arr[i]);
    }
    for(int i=n-2; i>=0; i--){
        right[i] = min(right[i+1], arr[i]);
    }

    int ans=1;
    for(int i=0; i<n-1; i++){
        ans += (left[i]<=right[i+1]);
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