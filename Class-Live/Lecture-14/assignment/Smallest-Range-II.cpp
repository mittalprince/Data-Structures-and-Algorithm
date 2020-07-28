#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);

int smallestRangeII(vector<int>& A, int K) {
    int n=A.size();
    if(n<=1) return 0;

    sort(A.begin(), A.end());
    int min_diff = A.back()-A.front();

    if(K==0) return min_diff;

    int begin_val =  A.front()+K;
    int end_val = A.back()-K;

    for(int i=0; i<n-1; i++){
        int max_val = max(end_val, A[i]+K);
        int min_val = min(begin_val, A[i+1]-K);

        min_diff = min(min_diff, abs(max_val-min_val));
    }

    return min_diff;
}

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    
    return 0;
}