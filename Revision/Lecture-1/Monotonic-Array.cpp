//https://leetcode.com/problems/monotonic-array/
#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define MOD 1000000007

bool isMonotonic(vector<int>& A) {
    int n=A.size();
    bool inc=true, dec=true;

    for(int i=1; i<n; i++){
        if(A[i]<A[i-1]){
            inc=false;
        }
        if(A[i]>A[i-1]){
            dec=false;
        }
    }
    return (inc||dec);
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