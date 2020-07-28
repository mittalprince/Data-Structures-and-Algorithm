#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);

double myPow(double x, int n) {
    if(n==1) return x;
    if(n==0) return 1.0;
    
    int t=n/2;
    if(n<0){
        x=1/x;
        t = -t;
    }
    double res=myPow(x, t);
    res *= res;
    if(n&1){
        res *= x;
    }
    return res;
}

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    
    return 0;
}