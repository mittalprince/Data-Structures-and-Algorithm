#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);

// check -> min step req to make A vector equal to A[0] or B vector to A[0]
// since we need to make all elemnt of either vector to be equal
// then we have two options make either vector equal to A[0] or B[0]
// we find min step in both options and return min of these options

int check(vector<int>&A, vector<int>&B){
    int target = A[0];
    int opt1=0, opt2=0;

    for(int i=0; i<A.size(); i++){
        if(A[i] != target && B[i] != target) return -1;
        if(A[i] != target) opt1++;
        else if(B[i] != target) opt2++;
    }

    return min(opt1, opt2);
}
int minDominoRotations(vector<int>& A, vector<int>& B) {
    int opt1 = check(A, B);
    int opt2 = check(B, A);

    if(opt1 == -1) return opt2;
    if(opt2 == -1) return opt1;

    return min(opt1, opt2);
}

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    
    return 0;
}