#include<iostream>
#include<vector>
#include<cstring>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);

int n, ct=0;
int board[100][100]={0};
vector<pair<int, int> >ans;

const int x[]={-2,-2,-1,-1,1,1,2,2};
const int y[]={-1,1,-2,2,-2,2,-1,1};

bool kyaSafe(int i, int j){
    for(int k=0; k<8; k++){
        if(i+x[k]>=0 && i+x[k]<n && j+y[k]>=0 && j+y[k]<n){
            if(board[i+x[k]][j+y[k]]) return false;
        }
    }
    return true;
}

bool NKnight(int placed, int row, int col){
    if(placed == n){
        for(int i=0;i<ans.size();i++){
			cout<<"{"<<ans[i].first<<"-"<<ans[i].second<<"} ";
		}
		cout<<" ";
		ct++;
		return false; // because we want other possibilities
    }
    if(row==n) return false; // if we encounter end of board we simply return false to find other possibilities
    if(col == n){
        return NKnight(placed, row+1, 0);
    }

    if(kyaSafe(row, col)){
        board[row][col]=1;
        ans.push_back({row, col});
        bool checkRem = NKnight(placed+1, row, col+1);
        if(checkRem) return true;
        board[row][col]=0;
        ans.pop_back();
    }
    //here we don't return false, as we have to consider all possibility, so if we cant place knight at given
    // row col we just incremnt the col and check other pissiblity
    return NKnight(placed, row, col+1);
}
int main(){
    cin>>n;
    NKnight(0, 0, 0);
    memset(board, false, sizeof(board));
    cout<<endl<<ct<<endl;
    return 0;
}