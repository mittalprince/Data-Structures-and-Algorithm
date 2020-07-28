#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);

// Link: https://leetcode.com/problems/minimum-falling-path-sum-ii/

int minFallingPathSum(vector<vector<int>>& A) {
    int n=A.size();
    int m = A[0].size();

    if(n==1 && m==1) return A[0][0];

    int prevpos=-1, prevFirstMin=0, prevSecondMin=0;

    for(int i=0; i<n; i++){

        int nextFirstMin=INT_MAX, nextSecondMin=INT_MAX, nextPos=-1;

        for(int j=0; j<m; j++){
            int curr = A[i][j] + (j==prevpos?prevSecondMin:prevFirstMin);

            if(curr<nextFirstMin){
                nextPos=j;
                nextSecondMin = nextFirstMin;
                nextFirstMin = curr;
            }
            else if(curr<nextSecondMin){
                nextSecondMin = curr;
            }
        }

        prevFirstMin = nextFirstMin;
        prevSecondMin = nextSecondMin;
        prevpos = nextPos;
    }

    return prevFirstMin;
}

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    
    return 0;
}