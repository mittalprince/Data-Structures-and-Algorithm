// https://leetcode.com/problems/reverse-integer/
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

int reverse(int x) {
    int res = 0;
    while(x != 0){
        int pop = x%10;
        x /= 10;
        if (res > INT_MAX/10 || (res == INT_MAX/10 && pop > 7))return 0;
        if (res < INT_MIN/10 || (res == INT_MIN/10 && pop < -8)) return 0;
        res = res*10 + pop;
    }
    return res;
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