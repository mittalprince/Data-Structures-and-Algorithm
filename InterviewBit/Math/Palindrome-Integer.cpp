#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);

int isPalindrome(int A) {
    if(A<0 || (A%10 == 0 && A!=0)) return false;
    
    int rev=0;
    while(A>rev){
        rev = rev*10+A%10;
        A /= 10;
    }
    
    if(A == rev || A == rev/10) return true;
    return false;
}

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    
    return 0;
}