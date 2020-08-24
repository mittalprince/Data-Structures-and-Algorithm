// https://leetcode.com/problems/sum-of-subarray-minimums/
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
#define mod 1000000007

int sumSubarrayMins(vector<int>& A) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n=A.size();
    if(n==0) return 0;

    stack<int>s;
    vector<int>left(n,-1), right(n, n);

    for(int i=0; i<n; i++){
        while(!s.empty() && A[s.top()]>=A[i]) s.pop();

        if(!s.empty())left[i]=s.top();
        s.push(i);
    }

    s=stack<int>();
    for(int i=n-1;i>=0;i--){
        while(!s.empty() && A[i]<A[s.top()]){
            s.pop();
        }
        if(!s.empty()){
            right[i]=s.top();
        }
        s.push(i);
    }

    int ans=0;
    for(int i=0; i<n; i++){
        ans += (((i-left[i])*(right[i]-i))%mod)*(A[i]%mod);
        ans %=mod;
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