#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);

int minKBitFlips(vector<int>& A, int k) {
    int n=A.size();
    vector<bool>flipped(n, 0); //Flipped[i] = 1 if we flip K consecutive bits A[i] A[i+1] ..... A[i+K-1].

    int totalFlippedFromPastWindowsForCurrIdx = 0;
    int req_flip=0;

    /*
    If totalFlippedFromPastWindowsForCurrIdx is even and A[i] is 0, we need to flip.
    If totalFlippedFromPastWindowsForCurrIdx is odd and A[i] is 1, we need to flip.
    */

    for(int i=0; i<n; i++){
        if(i>=k){
            if(flipped[i-k]){// if we make a flip operation at i-k index
                // then remove its count.
                totalFlippedFromPastWindowsForCurrIdx--; 
            }
        }

        if((totalFlippedFromPastWindowsForCurrIdx&1) == A[i]){
            if(i+k>n){
                return -1;
            }

            totalFlippedFromPastWindowsForCurrIdx++;
            flipped[i]=true;
            req_flip++;
        }
    }
    return req_flip;
}

// brute force
int minKBitFlips(vector<int>& A, int k) {
    int n=A.size();

    int req_flip=0;
    // travere all subarr of size k that start with 0 and flip al the numbers
    for(int i=0; i<=n-k; i++){
        if(A[i] == 0){
            req_flip++;
            for(int j=i; j<i+k; j++){
                A[j] = 1-A[j];
            }
        }
    }

    for(int i=n-k; i<n; i++){
        if(A[i] == 0) return -1;
    }
    return req_flip;
}

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    
    return 0;
}