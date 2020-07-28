#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);

/*
You are given two positive numbers A and B. You need to find the maximum valued integer X such that:

X divides A i.e. A % X = 0
X and B are co-prime i.e. gcd(X, B) = 1

Here, first we will remove the common factors of x and y from x by finding the gcd of x and y and
dividing x with that gcd.
*/
int gcd(int a, int b){
    if(b==0) return a;
    return gcd(b, a%b);
}
int cpFact(int A, int B) {
    while(gcd(A, B) != 1){
        A /= gcd(A, B);
    }
    return A;
}

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    
    return 0;
}