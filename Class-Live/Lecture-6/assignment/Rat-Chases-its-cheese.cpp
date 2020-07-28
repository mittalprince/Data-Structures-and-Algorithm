#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define MAX 10

bool check(char arr[][MAX], int n, int m, int i, int j){
    if(i<0||j<0||i>=n||j>=m||arr[i][j]=='X'||arr[i][j]=='1') return false;
    return true;
}

bool findPath(char arr[][MAX], char output[][MAX], int n, int m, int i, int j){
    if(i==(n-1) && j==(m-1) && arr[i][j] == 'O'){
        output[i][j]='1';
        return true;
    }
    
    if(check(arr, n, m, i, j)){
        arr[i][j] = '1';
        output[i][j] = '1';
        
        if(findPath(arr, output, n, m, i-1, j)) return true;
        if(findPath(arr, output, n, m, i+1, j)) return true;
        if(findPath(arr, output, n, m, i, j-1)) return true;
        if(findPath(arr, output, n, m, i, j+1)) return true;

        arr[i][j] = 'O';
        output[i][j] = '0';
    }
    return false;
}
int main(){
    int n,m;
    cin>>n>>m;
    char arr[MAX][MAX], output[MAX][MAX];
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>arr[i][j];
        }
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            output[i][j] = '0';
        }
    }
    if(findPath(arr, output, n, m, 0, 0)){
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                cout<<output[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    else cout<<"NO PATH FOUND\n";
    return 0;
}