#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);

bool isPowerOfFour(int num) {
    if(ceil(log10(num)/log10(4)) -  floor(log10(num)/log10(4)) == 0 )
        return true;
    return false;

}

bool isPowerOfFour(int n) {
    if (n < 1) return false;
    while (n % 4 == 0){
        n /= 4;
    }
    return n == 1;
}

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    
    return 0;
}