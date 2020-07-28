#include<iostream>
#include<vector>
#include<cstring>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define MAX 1000000

//complexity NLongLongN
void PrimeSieve(int N){
    bool isPrime[MAX];
    memset(isPrime, true, sizeof(isPrime));
    for(int i=2; i*i<=N; i++){
        if(isPrime[i]){
            // j ko 2*i ki jagah i*i se bhi start kar sakta hai
            for(int j=i*i; j<=N; j+=i) isPrime[j]=false;
        }
    }
    for(int i=2; i<=N; i++){
        if(isPrime[i]) cout<<i<<" ";
    }
    cout<<endl;
}
int main(){
    int n;
    cin>>n;
    PrimeSieve(n);
    return 0;
}