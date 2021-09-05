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

int main(){
    int n;
    cin>>n;
    vector<int>arr(n);

    ip(arr, n);
    long long ans = 0;

    for(int i=1; i<n-1; i++){
        int small=0;
        for(int j=i+1; j<n; j++){
            if (arr[i]>arr[j])small++;
        }
        int great=0;
        for(int j=i-1; j>=0; j--){
            if (arr[i]<arr[j])great++;
        }
        ans += small*great;
    }
    cout<<ans<<endl;
    return 0;
}

/*
Input: 
5
5 3 4 2 1

output: 7

Input: 
*/