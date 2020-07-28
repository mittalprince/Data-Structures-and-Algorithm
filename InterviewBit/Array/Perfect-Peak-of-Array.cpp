// https://www.interviewbit.com/problems/perfect-peak-of-array/
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

int perfectPeak(vector<int> &A) {
    int n=A.size();
    vector<int>left(n, 0), right(n, 0);
    left[0]=A[0];
    for(int i=1; i<n; i++){
        left[i] = max(left[i-1], A[i]);
    }
    right[n-1]=A[n-1];
    for(int i=n-2; i>=0; i--){
        right[i] = min(right[i+1], A[i]);
    }
    
    for(int i=1; i<n-1; i++){
        if(A[i]>left[i-1] and A[i]<right[i+1])return 1;
    }
    return 0;
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