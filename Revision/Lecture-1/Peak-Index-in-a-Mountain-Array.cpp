#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define MOD 1000000007

peakIndexInMountainArray(vector<int>& A) {
    int s=0, e=A.size()-1;

    while(s<=e){
        int mid = (s+e)/2;

        if(A[mid]>A[mid-1] && A[mid]>A[mid+1])return mid;
        if(A[mid]<A[mid+1])s=mid+1;
        else e=mid-1;
    }
    return s;
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