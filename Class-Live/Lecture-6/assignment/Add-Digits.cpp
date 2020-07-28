#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);

int addDigits(int n) {
    if(n <= 9) return n;
    
    while(n>9){
        int temp = 0;
        while(n>0){
            temp += n%10;
            n /= 10;
        }
        n = temp;
    }
    return n;
}

int main(){
    int n;
    cin>>n;
    cout<<addDigits(n)<<endl;
    return 0;
}