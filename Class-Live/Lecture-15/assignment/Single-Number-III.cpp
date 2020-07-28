#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);

vector<int> singleNumber(vector<int>& nums) {
    int xor_val = 0;

    for(int i: nums){
        xor_val ^= i;
    }

    int setBit = xor_val&~(xor_val-1);

    int a=0, b=0;
    for(int i: nums){
        if(setBit&i){
            a ^= i;
        }
        else b ^= i;
    }

    return {a,b};
}

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    
    return 0;
}