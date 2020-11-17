//https://leetcode.com/problems/daily-temperatures/
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

vector<int> dailyTemperatures(vector<int>& T) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    stack<int>s;
    int n=T.size();
    vector<int>ans(n, 0);

    for(int i=n-1; i>=0; i--){
        while(!s.empty() and T[s.top()]<=T[i])s.pop();

        ans[i] = s.empty()?0:s.top()-i;
        s.push(i);
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