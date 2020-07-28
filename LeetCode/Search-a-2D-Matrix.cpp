// https://leetcode.com/problems/search-a-2d-matrix/
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

bool searchMatrix(vector<vector<int>>& matrix, int target) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n=matrix.size();
    int m=n?matrix[0].size():0;

    if(!n or !m)return false;

    int r=0,c=m-1;
    while(r>=0 and r<n and c>=0 and c<m){
        int val = matrix[r][c];
        if(val==target)return true;
        if(val<target){
            r++;
        }
        else c--;
    }
    return false;
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