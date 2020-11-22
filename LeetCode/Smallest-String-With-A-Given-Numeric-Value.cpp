//https://leetcode.com/problems/smallest-string-with-a-given-numeric-value/
#include<iostream>
#include<vector>
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

string getSmallestString(int n, int k) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s(n, 'a');
    k -=n;

    for(int i=n-1; i>=0; i--){
        int d = min(k, 25);
        s[i] += d;
        k -= d;
    }
    return s;
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