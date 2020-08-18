// https://hack.codingblocks.com/app/contests/1496/99/problem
#include<iostream>
#include<vector>
#include<cstring>
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
#define cols 5
#define rows 13

void matrix(int arr[][cols], int temp[][cols], int h){
    for(int i=0; i<h; i++){
        for(int j=0; j<cols; j++){
            arr[i][j]=temp[i][j];
        }
    }
}

void somePower(int h, int arr[rows][cols]){
    for(int i=h-5; i<h; i++){
        for(int j=0; j<cols; j++){
            if(arr[i][j] == -1){
                arr[i][j]=0;
            }
        }
    }
}

void findMaxScore(int arr[rows][cols], int i, int j, int &ans, int sum){
    if(i<0||j<0||j>=cols){
        return;
    }

    if(i==0 or j==0){
        sum += arr[i][j];
        ans = max(ans, sum);
        return;
    }
    sum += arr[i][j];
    findMaxScore(arr, i-1, j-1, ans, sum);
    findMaxScore(arr, i-1, j, ans, sum);
    findMaxScore(arr, i-1, j+1, ans, sum);
}

void solve(){
    int h;
    cin>>h;
    int arr[rows][cols], temp[rows][cols];
    memset(arr, 0, sizeof(arr));

    for(int i=0; i<h; i++){
        for(int j=0; j<5; j++){
            cin>>arr[i][j];
            temp[i][j] = arr[i][j];
        }
    }  
    int ans=-inf;
    if(h<=5){
        somePower(h, arr);
        findMaxScore(arr, h, 2, ans, 0);
    }  
    for(int i=h; i>=5; i--){
        matrix(arr, temp, h);
        somePower(i, arr);
        findMaxScore(arr, h, 2, ans, 0);
    }
    cout<<ans<<endl;
}

int main(){

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}