#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);

bool hasAlternatingBits(int n) {
    int curr = n%2;
    n /= 2;

    while(n>0){
        if(curr == n%2) return false;
        curr = n%2;
        n /=2;
    }
    return true;
}

bool hasAlternatingBits(int n) {
    return (n & (n >> 1)) == 0 && (n & (n >> 2)) == (n >> 2);
}

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    
    return 0;
}