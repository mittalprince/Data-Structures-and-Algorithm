#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);

int largestSumAfterKNegations(vector<int>& A, int K) {
    int n=A.size();
    int mi = INT_MAX;

    sort(A.begin(), A.end());
    for(int i=0; i<n; i++){
        if(A[i]<0 && K){
            A[i] = -A[i];
            K--;
        }
        mi = min(mi, A[i]);
    }

    int sum=0;
    for(int i: A){
        sum += i;
    }

    if(K==0||K%2==0) return sum;

    return (sum-(2*mi));
}

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    
    return 0;
}