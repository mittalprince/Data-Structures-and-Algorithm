#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);

int reverse(int A) {
    long long ans=0;
    bool neg = 0;
    if(A<0){
        A *= -1;
        neg = 1;
    }
    while(A>0){
        ans = ans*10+A%10;
        A /= 10;
        
        if(ans>INT_MAX) return 0;
        if(neg && -ans<INT_MIN) return 0;
    }
    
    if(neg) ans *= -1; 
    return ans;
}

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    
    return 0;
}