//https://leetcode.com/problems/minimum-domino-rotations-for-equal-row/
#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define ip1(arr, n) for(int i=1; i<=n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define debug(x) cout<<x<<"\n";
#define inf 1e9
#define INF 1e16
#define MOD 1000000007

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

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    int n;
    cin>>n;
    vector<int> arr(n);
    
    return 0;
}