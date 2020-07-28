#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);

void printNumbers(int n, int a){
    if(a>n){
        return;
    }
    cout<<a<<" ";
    int i=(a==0);
    for(; i<=9; i++){
        printNumbers(n, a*10+i);
    }
}

int main(){
    int n;
    cin>>n;
    printNumbers(n, 0);
    cout<<endl;
    return 0;
}