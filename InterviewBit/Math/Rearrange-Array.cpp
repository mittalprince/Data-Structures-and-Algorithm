#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);

// Rearrange a given array so that Arr[i] becomes Arr[Arr[i]] with O(1) extra space.
// Now, we will do a slight trick to encode 2 numbers in one index.
// 1) Increase every Array element Arr[i] by (Arr[Arr[i]] % n)*n.
// 2) Divide every element by N.
// A = B + C * N   if ( B, C < N )
// A % N = B
// A / N = C
// old val will be arr[i]%n and new val will be arr[i]/n

void arrange(vector<int> &A)
{
    int n=A.size();
    for(int i=0; i<n; i++){
        A[i] += (A[A[i]]%n)*n;
    }
    
    for(int i=0; i<n; i++){
        A[i] = A[i]/n;
    }
}

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    
    return 0;
}