// https://leetcode.com/problems/rotate-image/
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

void rotate(vector<vector<int>>& matrix) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n=matrix.size();
    int m=matrix[0].size();
    
    for(int i=0; i<n; i++){
        for(int j=0; j<i; j++){
            if(i!=j){
                swap(matrix[i][j], matrix[j][i]);
            }
        }
    }
    
    for(int i=0; i<n; i++){
        int l=0, r=n-1;
        while(l<r){
            swap(matrix[i][l++],matrix[i][r--]);
        }
    }
    
}

int main(){

/*
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
*/

    int n;
    cin>>n;
    vector<int> arr(n);
    
    return 0;
}