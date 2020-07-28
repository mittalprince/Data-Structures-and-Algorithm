#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);

uint32_t reverseBits(uint32_t n) {
    uint32_t ret = 0;
    for (int i = 0; i < 32; i ++){
        ret = ret << 1 | (n & 1);
        n >>= 1;
    }
    return ret;
}

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    
    return 0;
}