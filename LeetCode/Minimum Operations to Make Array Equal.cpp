// https://leetcode.com/problems/minimum-operations-to-make-array-equal/
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

int minOperations(int n) {

    int a=1;
    long long sum=0;
    for(int i=0; i<n; i++){
        sum += a;
        a += 2;
    }

    sum = sum/n;
    a=1;
    int ans=0;
    for(int i=0; i<n; i++){
        ans += abs(sum-a);
        a += 2;
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