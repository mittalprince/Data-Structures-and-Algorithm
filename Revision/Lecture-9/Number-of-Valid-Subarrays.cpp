// https://code.dennyzhang.com/number-of-valid-subarrays.
#include<iostream>
#include<vector>
#include<stack>
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

int validSubarrays(vector<int>&arr){
    int n=arr.size();

    vector<int>next_smallest(n, n);
    stack<int>s;

    for(int i=n-1; i>=0; i--){
        while(!s.empty() and arr[s.top()]>arr[i])s.pop();
        if(!s.empty()){
            next_smallest[i] = s.top();
        }
        s.push(i);
    }
    
    int ans=0;
    for(int i=0; i<n; i++){
        ans += next_smallest[i]-i;
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
    ip(arr, n);

    int ans = validSubarrays(arr);
    cout<<ans<<endl;
    return 0;
}