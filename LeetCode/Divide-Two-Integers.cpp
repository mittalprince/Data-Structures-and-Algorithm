//https://leetcode.com/problems/divide-two-integers/
#include<iostream>
#include<vector>
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

int divide(int dividend, int divisor) {
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);

    if(dividend == INT_MIN and divisor==-1){
        return INT_MAX;
    }

    long dvd = labs(dividend), dvs=labs(divisor);
    int sign = dividend > 0 ^ divisor > 0 ? -1 : 1;
    long ans=0;

    while(dvd >= dvs){
        long temp=dvs, m=1;
        while(temp<<1 <= dvd){
            temp <<= 1;
            m <<= 1;
        }
        ans += m;
        dvd -= temp;
    }

    return ans*sign;
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