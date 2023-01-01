// https://leetcode.com/contest/problems/partition-string-into-substrings-with-values-at-most-k/
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

int minimumPartition(string s, int k) {
    int ans=0;
    for(char &c: s) c = c-'0';
    for(int i: s) if(i>k) return -1;
    long long t=0;
    for(int i: s){
        t = t*10 + i;
        if(t>k){
            ans++;
            t = i;
        }
    }
    return ans+1;
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