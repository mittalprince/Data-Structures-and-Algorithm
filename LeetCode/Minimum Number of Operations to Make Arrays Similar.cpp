// https://leetcode.com/problems/minimum-number-of-operations-to-make-arrays-similar/
#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<cstdlib>
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

long long makeSimilar(vector<int>& nums, vector<int>& target) {
    vector<vector<int>>a(2), b(2);
    for(int i: nums){
        a[i&1].push_back(i);
    }
    for(int i: target){
        b[i&1].push_back(i);
    }
    sort(a[0].begin(), a[0].end());
    sort(a[1].begin(), a[1].end());
    sort(b[0].begin(), b[0].end());
    sort(b[1].begin(), b[1].end());
    long long ans = 0;
    for(int i=0; i<a[0].size(); i++){
        ans += abs(a[0][i]-b[0][i])/2;
    }
    for(int i=0; i<a[1].size(); i++){
        ans += abs(a[1][i]-b[1][i])/2;
    }
    return ans/2;
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