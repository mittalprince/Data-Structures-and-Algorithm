#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);

int minDeletionSize(vector<string>& A) {
    int ans=0;

    int n=A.size();
    int m = A[0].size();

    for(int j=0; j<m; j++){
        for(int i=0; i<n-1; i++){
            if(A[i][j] > A[i+1][j]){
                ans++;
                break;
            }
        }
    }
    return ans;
}

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    
    return 0;
}