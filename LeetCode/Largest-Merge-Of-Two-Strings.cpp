//https://leetcode.com/problems/largest-merge-of-two-strings/
#include<iostream>
#include<vector>
#include<cstring>
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

string largestMerge(string x, string y) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string r;
    int i = 0, j = 0;
    for (i=0,j=0;i<x.length()&&j<y.length();) {
        if (strcmp(&x[i], &y[j]) > 0) {
            r += x[i++];
        } else {
            r += y[j++];
        }
    }
    r += x.substr(i) + y.substr(j);
    return r;
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