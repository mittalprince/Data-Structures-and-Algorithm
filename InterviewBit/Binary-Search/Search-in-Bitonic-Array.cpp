// https://www.interviewbit.com/problems/search-in-bitonic-array/
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

int findPeak(vector<int>&A){
    int s=0, e=A.size()-1;
    
    while(s<=e){
        int mid = s+(e-s)/2;
        if(A[mid]<A[mid+1])s=mid+1;
        else e=mid-1;
    }
    return s;
}

int solve(vector<int> &A, int B) {
    int pivot = findPeak(A);
    int s=0, e=pivot-1;
    
    while(s<=e){
        int mid =(s+e)/2;
        if(A[mid] == B)return mid;
        if(A[mid]<B)s=mid+1;
        else e=mid-1;
    }
    
    s=pivot, e=A.size()-1;
    while(s<=e){
        int mid =(s+e)/2;
        if(A[mid] == B)return mid;
        if(A[mid]<B)s=mid+1;
        else e=mid-1;
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