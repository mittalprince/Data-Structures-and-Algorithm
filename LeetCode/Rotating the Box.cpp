// https://leetcode.com/problems/rotating-the-box/
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

vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
    int n = box.size();
    int m = box[0].size();
    for(int i=0; i<n; i++){
        int empty = m-1;
        for(int j=m-1; j>=0; j--){
            if(box[i][j] == '*'){
                empty = j-1;
            } else if(box[i][j]=='#'){
                box[i][j] = '.';
                box[i][empty] = '#';
                empty--;
            }
        }
    }
    vector<vector<char>>ans(m, vector<char>(n));
    for(int i = 0; i<n; ++i){
        for(int j = m-1; j>=0; --j)
            ans[j][n-i-1] = box[i][j];
    }
    return ans;
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