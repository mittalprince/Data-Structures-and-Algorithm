// https://leetcode.com/problems/valid-tic-tac-toe-state/
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

bool validTicTacToe(vector<string>& board) {
    int total_x=0, total_o=0, diagonal=0, antidiagonal=0;
    int row[3]={0}, col[3]={0};

    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            if(board[i][j]=='X'){
                total_x++;
                row[i]++;
                col[j]++;
                if(i+j==2)antidiagonal++;
                if(i==j)diagonal++;
            }
            else if(board[i][j]=='O'){
                total_o++;
                row[i]--;
                col[j]--;
                if(i+j==2)antidiagonal--;
                if(i==j)diagonal--;
            }
        }
    }

    if(total_x-total_o<0 or total_x-total_o>1)return false;

    bool xwins = (antidiagonal == 3 || diagonal == 3);
    bool owins = (antidiagonal == -3 || diagonal == -3);

    for(int i=0; i<3; i++){
        if(row[i]==3 or col[i]==3)xwins=true;
        if(row[i]==-3 or col[i]==-3)owins=true;
    }

    if(xwins and owins)return false;
    if(xwins and total_x-total_o != 1)return false;
    if(owins and total_x != total_o)return false;

    return true;
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