// https://leetcode.com/problems/minimum-one-bit-operations-to-make-integers-zero/
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

int minimumOneBitOperations(int n) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int msb=0;
    if(n<=1)return n;

    while((1<<msb) <= n){
        msb++;
    }

    return ((1<<msb)-1) - minimumOneBitOperations(n-(1<<(msb-1)));
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