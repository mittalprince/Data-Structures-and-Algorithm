#include<iostream>
#include<vector>
#include<cstring>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define MAX 100
bool visited[MAX][MAX];
int ct=0;

const int x[]={-2,-2,-1,-1,1,1,2,2};
const int y[]={-1,1,-2,2,-2,2,-1,1};

bool isSafe(int i, int j, int n){
    for(int k=0; k<8; k++){
        if(i+x[k]>=0 && i+x[k]<n && j+y[k]>=0 && j+y[k]<n){
            if(visited[i+x[k]][j+y[k]]) return false;
        }
    }
    return true;
}
void printNKnight(int n, int i, int sr, int sc, string out){
    if (i == n) {
        cout<<out<<" ";
        ct++;
        return;
    }

    for(int row = sr; row < n; row++) {
        for (int col = (row == sr? sc: 0); col < n; col++) {
            if (visited[row][col] == false && isSafe(row, col, n)) {
                visited[row][col] = true;
                printNKnight(n, i + 1, row, col + 1, out + "{" + to_string(row) + "-" + to_string(col) + "} ");
                visited[row][col] = false;
            }
        }
    }
}
// void printKnight(int n, int i, int row, int cols, string out){
//     if(row<0||row>=n||cols<0||cols>=n){
//         return;
//     }
//     if(i==n){
//         cout<<out<<" ";
//         ct++;
//         return;
//     }

//     if(cols==n){
//         printKnight(n,i,row+1, 0, out);
//         return;
//     }

//     if(!visited[row][cols] && isSafe(row,cols,n)){
//         visited[row][cols]=true;
//         out += "{"+to_string(row)+ "-"+to_string(cols)+"} ";
//         printKnight(n, i+1, row, cols+1, out);
//         visited[row][cols] = false;
//     }
// }

int main(){
    int n;
    cin>>n;
    memset(visited, false, sizeof(visited));
    printNKnight(n, 0, 0, 0, "");
    cout<<endl<<ct<<endl;
    return 0;
}