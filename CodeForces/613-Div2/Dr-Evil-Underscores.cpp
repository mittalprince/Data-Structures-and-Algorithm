// https://codeforces.com/contest/1285/problem/D
// https://codeforces.com/contest/1285/problem/D
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

/*
Since the ans can have max 30 bits, so we check one by one wether ith bit include in ans or not.

For the ith bit to be set in ans we must have both 0 and 1 at ith bit in arr only then this ith bit can be set in ans
as whatever number we chose it will set the ith bit(as if we choose 0 it will exor with 1 and give 1 and vice versa)

So we segregate the vector in two vectors where ith bit set in arr numbers, if either vector in empty, 
means the ith bit need not to bet set in ans variable, so in this case we simplly call for bit-1

While if we have elemnt in both vector, we know the ith bit must be set so for (bit-1) total bits we find the min ans using recursion
and add their min to (1<<bit).
*/
ll solve(vector<int>&arr, int bit){
    if(bit<0 or arr.empty()){
        return 0;
    }
    ll mask = (1ll<<bit);
    vector<int>zero, one;
    for(int i: arr){
        if(i&mask)one.push_back(i);
        else zero.push_back(i);
    }

    if(one.empty())return solve(zero, bit-1);
    if(zero.empty())return solve(one, bit-1);

    return min(solve(one, bit-1), solve(zero, bit-1))+ (1<<bit);
}

int main(){

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    int n;
    cin>>n;
    vector<int> arr(n);
    ip(arr, n);
    cout<<solve(arr, 30)<<endl;
    return 0;
}