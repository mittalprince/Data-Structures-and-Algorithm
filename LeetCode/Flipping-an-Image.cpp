//https://leetcode.com/problems/flipping-an-image/
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

vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {
    for(int i=0; i<A.size(); i++){
        int l=0, r=A[i].size()-1;
        while(l<r){
            swap(A[i][l], A[i][r]);
            l++;
            r--;
        }
    }

    for(int i=0; i<A.size(); i++){
        for(int j=0; j<A[i].size(); j++){
            if(A[i][j]) A[i][j]=0;
            else A[i][j]=1;
        }
    }
    return A;
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