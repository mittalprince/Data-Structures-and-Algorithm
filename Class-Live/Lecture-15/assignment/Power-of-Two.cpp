#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);

bool isPowerOfTwo(int n) {
    if(n==1)
    return true;
    if(n>0){
    if(!(n & (n-1)))
    return true;
    }
    return false;  
}

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    
    return 0;
}