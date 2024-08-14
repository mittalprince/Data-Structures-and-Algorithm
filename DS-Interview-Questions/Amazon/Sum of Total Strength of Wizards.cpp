// https://leetcode.com/problems/sum-of-total-strength-of-wizards/
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

const long long mod = 1000000007;
int totalStrength(vector<int>& arr) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n=arr.size();
    vector<long long>prefix(n+2, 0);
    long long sum = 0;
    for(int i=1; i<=n; i++){
        sum += arr[i-1];
        sum %= mod;
        prefix[i] = (prefix[i-1] + sum)%mod;
    }
    
    vector<int>left(n,-1), right(n,n);
    stack<int>s;
    for(int i=0; i<n; i++){
        while(!s.empty() && arr[s.top()]>=arr[i])s.pop();
        if(!s.empty())left[i] =s.top();
        s.push(i);
    }
    while(!s.empty())s.pop();
    
    // for(int i=0; i<n; i++){
    //     while(!s.empty() && arr[s.top()]>arr[i]){
    //         right[s.top()]=i;
    //         s.pop();
    //     }
    //     s.push(i);
    // }
    for(int i=n-1;i>=0;i--){
        while(!s.empty() && arr[i]<arr[s.top()]){
            s.pop();
        }
        if(!s.empty()){
            right[i]=s.top();
        }
        s.push(i);
    }
    //make prefix table indexing to 1
    long long ans=0;
    for(int i=0; i<n; i++){
        long long val = (long long)((i-left[i])*(prefix[right[i]]-prefix[i]))%mod + mod*2 - ((right[i]-i)*(prefix[i]-prefix[left[i]<0 ? 0 : left[i]]))%mod;
        ans = (ans + val*arr[i])%mod;
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