// https://leetcode.com/problems/replace-elements-with-greatest-element-on-right-side/
#include<iostream>
#include<vector>
#include<algorithm>
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

vector<int> replaceElements(vector<int>& arr) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    vector<int> res;
    int myMax = INT_MIN;
    for(int i = arr.size() - 1; i >= 1; i--)
    {
        myMax = max(myMax, arr[i]);
        res.push_back(myMax);
    }
    
    reverse(res.begin(), res.end());
    
    res.push_back(-1);
        
    return res;
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