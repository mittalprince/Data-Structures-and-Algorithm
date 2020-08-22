// https://leetcode.com/problems/next-greater-element-ii/
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

vector<int> nextGreaterElements(vector<int>& arr) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n = arr.size();
    vector<int>ans(n,0);

    stack<int>s;

    for(int i=2*n-1; i>=0; i--){
        while(!s.empty() and s.top()<=arr[i%n])s.pop();
        ans[i%n] = s.empty()?-1:s.top();
        s.push(arr[i%n]);
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