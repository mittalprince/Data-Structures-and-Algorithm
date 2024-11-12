// https://leetcode.com/problems/battleships-in-a-board/
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

int countBattleships(vector<vector<char>>& board) {
    if (board.empty() || board[0].empty()) { return 0; }
    int m = board.size(), n = board[0].size(), cnt = 0;

    for (int r = 0; r < m; r++)
        for (int c = 0; c < n; c++)
            cnt += board[r][c] == 'X' && (r == 0 || board[r - 1][c] != 'X') && (c == 0 || board[r][c - 1] != 'X');

    return cnt;
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