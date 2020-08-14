// https://hack.codingblocks.com/app/practice/1/535/problem
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
char arr[15][15], output[15][15];

bool isValid(int i, int j){
    return (i>=0 and i<n and j>=0 and j<m and arr[i][j]=='O');
}

bool findpath(int i, int j){
    if(i==(n-1) and j==(m-1) and arr[i][j]=='O'){
        output[i][j]='1';
        return true;
    }

    if(isValid(i,j)){
        arr[i][j]='1';
        output[i][j]='1';

        if(findpath(i+1, j))return true;
        if(findpath(i-1, j))return true;
        if(findpath(i, j-1))return true;
        if(findpath(i, j+1))return true;
        output[i][j]='0';
        arr[i][j]='O';
    }
    return false;
}

int main(){

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    cin>>n>>m;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>arr[i][j];
            output[i][j]='0';
        }
    }

    if(findpath(0, 0)){
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