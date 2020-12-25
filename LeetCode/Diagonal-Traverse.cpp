//https://leetcode.com/problems/diagonal-traverse/
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

vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n=matrix.size();
    if(!n)return {};

    int m=matrix[0].size();

    vector<int>ans;
    int r=0, c=0;

    for(int i=0; i<n*m; i++){
        ans.push_back(matrix[r][c]);
        if((r+c)&1){ // moving down
            if(r==n-1)c++;
            else if(c==0)r++;
            else{
                r++; c--;
            }
        }
        else{// moving up
            if(c==m-1)r++;
            else if(r==0)c++;
            else{
                r--;c++;
            }
        }
    }
    return ans;
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