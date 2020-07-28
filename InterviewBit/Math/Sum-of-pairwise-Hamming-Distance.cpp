#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define mod 1000000007

/*
Hamming distance between two non-negative integers is defined as the number of positions,
at which the corresponding bits are different.

For example,
HammingDistance(2, 7) = 2, as only the first and the third bit differs in the binary 
representation of 2 (010) and 7 (111).

Let X be the number of elements equal to 0, and Y be the number of elements equals to 1.
Then, sum of hamming distance of all pair of elements equals 2XY, 
as every pair containing one element from X and one element from Y contribute 1 to the sum.
*/

int hammingDistance(const vector<int> &A) {
    long long ans=0;
    
    for(int i=31; i>=0; i--){
        long long one=0, zero=0;
        for(int j=0; j<A.size(); j++){
            if((A[j]>>i)&1) one++;
            else zero++;
        }
        ans += ((2*one*zero)%mod);
    }
    return ans%mod;
}
int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    
    return 0;
}