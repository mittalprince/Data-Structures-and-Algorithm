#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);

/*
Given two numbers n and k, we need to find the minimum number of flips required to maximize given 
number by flipping its bits such that the resulting number has exactly k set bits.
Note : K must be less than number of bits in n.

Examples :

Input : n = 14, k = 2
Output : Min Flips = 1
Explanation : 
Binary representation of 14 = 1110
Largest 4-digit Binary number with
2 set bit = 1100
Conversion from 1110 to 1100 
requires 1 flipping

Input : n = 145, k = 4
Output : Min Flips = 3
Explanation : 
Binary representation of 145 = 10010001
Largest 8-digit Binary number with 
4 set bit = 11110000
Conversion from 10010001 to 11110000 
requires 3 flipping
*/

/* Logic
let n = 145 (10010001), k = 4

size = log2(n) + 1 = log2(145) + 1 
                   = 7 + 1 = 8 

max = pow(2, k) -1 = pow(2, 4) - 1 
                   = 16 - 1 = 15 (1111) 

max = max << (size - k) = 15 << (8 - 4) 
                        = 240 (11110000)

number of set bit in  =  no. of set bit in 
(n XOR max )              (145 ^ 240 ) 
                      = 3
*/

void solve(){
    int n, k;
    cin>>n>>k;

    int size = log2(n)+1;

    int max_val = pow(2, k);
    max_val = (max_val << (size-k));

    int xorVal = (max_val ^ n);
    cout<<__builtin_popcount(xorVal)<<endl;
}

int main(){
    int t;
    cin>>t;
     while(t--){
         solve();
    }
    return 0;
}