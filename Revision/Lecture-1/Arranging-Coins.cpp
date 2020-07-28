#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define MOD 1000000007

int arrangeCoins(int n) {
    long long s=0, e=n;

    while(s<=e){
        long long mid = (s+e)/2;
        long long t = mid*(mid+1)/2;

        if(t == n) return mid;
        else if(t<n) s=mid+1;
        else e=mid-1;
    }

    long long t = s*(s+1)/2;
    return (t==n)?s:s-1;
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