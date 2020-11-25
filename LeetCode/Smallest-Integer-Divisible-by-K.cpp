//https://leetcode.com/problems/smallest-integer-divisible-by-k/
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

int smallestRepunitDivByK(int K) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    if(K%2==0)
        return -1;
    int remainder=0;
    for(int i=1;i<=K;i++)
    {
        remainder=(remainder*10+1)%K;
        if(remainder==0)
            return i;
    }
    return -1;
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