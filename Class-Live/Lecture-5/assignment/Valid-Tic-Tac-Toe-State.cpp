#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define MAX 3

bool validTicTacToe(vector<string>&arr){
    int total_x=0, total_o=0, diagonal=0, antidiagonal=0;
    int row[MAX]={0}, col[MAX]={0};

    for(int i=0; i<MAX; i++){
        for(int j=0; j<MAX; j++){
            if(arr[i][j] == 'X'){
                row[i]++;
                col[j]++;
                total_x++;
                if(i==j) diagonal++;
                if(i+j == (MAX-1)) antidiagonal++;
            }
            else if(arr[i][j]=='O'){
                row[i]--;
                col[j]--;
                total_o++;
                if(i==j) diagonal--;
                if(i+j == (MAX-1)) antidiagonal--;
            }
        }
    }
    // cout<<"1 ";
    if((total_x-total_o)<0 || (total_x-total_o)>1) return false;

    bool xwins = (antidiagonal == 3 || diagonal == 3), owins = (antidiagonal == -3 || diagonal == -3);
    for(int i=0; i<MAX; i++){
        if(row[i]==3 || col[i]==3){
            xwins=true;
        }
        if(row[i]==-3 || col[i]==-3){
            owins=true;
        }
    }
    // cout<<owins<<" "<<xwins<<endl;
    // cout<<"2";
    if(xwins && owins) return false;
    // cout<<"3";
    if(xwins && total_x-total_o != 1) return false;
    // cout<<"4";
    if(owins && total_x!=total_o) return false;
    // cout<<"5";
    return true;
}

int main(){
    vector<string> board(MAX);
    for(int i=0; i<MAX; i++){
        cin>>board[i];
    }
    if(validTicTacToe(board)) cout<<"true\n";
    else cout<<"false\n";
    return 0;
}