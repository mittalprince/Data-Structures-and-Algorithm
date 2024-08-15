// https://leetcode.com/problems/word-search/
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

int n,m;
bool dfs(vector<vector<char>>& board, string word, int i, int j, int k){
    if(i<0 || i>=n || j<0 || j>=m || board[i][j] != word[k])return false;
    if(k == word.length() - 1) return true;

    char ch = board[i][j];
    board[i][j] = '*';
    bool check = dfs(board, word, i + 1, j, k + 1) ||
                 dfs(board, word, i - 1, j, k + 1) ||
                 dfs(board, word, i, j + 1, k + 1) ||
                 dfs(board, word, i, j - 1, k + 1);

    board[i][j] = ch;
    return check;
}

bool exist(vector<vector<char>>& board, string word){
    n = board.size();
    m = board[0].size();

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(dfs(board, word, i, j, 0))return true;
        }
    }
    return false;
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