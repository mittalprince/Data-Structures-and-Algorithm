#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);

void check(int n, int m, int i, int j, int &ans){
    if(i>=n||j>=m) return;
    if(i==(n-1) && j==(m-1)){
        ans++;
        return;
    }
    check(n, m, i+1, j, ans);
}

int uniquePaths(int m, int n) {
    // m+n-2 C n-1 = (m+n-2)! / (n-1)! (m-1)! 
    long long ans = 1;
    for (int i = n; i < (m + n - 1); i++) {
        ans *= i;
        ans /= (i - n + 1);
    }
    return (int)ans;
}

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    
    return 0;
}