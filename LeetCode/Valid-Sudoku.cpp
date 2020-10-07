// https: //leetcode.com/problems/valid-sudoku/
#include<iostream>
#include<vector>
#include<cmath>
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

const int n=9;

bool isSafe(vector<vector<char>>& board, int i, int j, char number){
    for(int k=0; k<n; k++){
        if(board[i][k]==number or board[k][j]==number)return false;
    }

    int N = sqrt(n);
    int starti = (i/N)*N;
    int startj = (j/N)*N;

    for(int k=starti; k<starti+N; k++){
        for(int l=startj; l<startj+N; l++){
            if(board[k][l]==number)return false;
        }
    }
    return true;
}

bool solve(vector<vector<char>>& board, int i, int j){
    if(i==n)return true;

    if(j==n)return solve(board, i+1, 0);

    if(board[i][j]=='.')return solve(board, i, j+1);
    char temp = board[i][j];
    board[i][j] = '.';
    bool checkCurrResult = isSafe(board, i, j, temp);
    board[i][j]=temp;

    return checkCurrResult and solve(board, i, j+1);

}

bool isValidSudoku(vector<vector<char>>& board) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    return solve(board, 0, 0);
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