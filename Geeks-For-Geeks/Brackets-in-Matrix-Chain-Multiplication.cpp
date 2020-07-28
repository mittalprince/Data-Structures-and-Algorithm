#include<iostream>
#include<vector>
#include<cstring>
#include<climits>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define MAX 105
ll dp[MAX][MAX];
ll bracket[MAX][MAX];

/*
Logic:
dp[i][j] -> if i place and open brces on ith index anf close on jth index what will be the min MCM cost

Points
1. dp[i][j] = 0 cost to multiply each matix with itself
2. In above step we have cal cost of len 1 matrxi
3. Now we cal cost, when we multiply 2 matrix, then cost to multiply 3 and so on until n-1
4. dp[i][j] = dp[i][k]+dp[k+1][j] +arr[i]*arr[k+1]*arr[j+1] 
*/

void printBracket(int i, int j){

    if(i==j){
        cout<<(char)(i+'A');
        return;
    }
    cout<<"(";
    printBracket(i, bracket[i][j]);
    printBracket(bracket[i][j]+1, j);
    cout<<")";
}

void solve(){
    int n;
    cin>>n;
    int arr[n];
    ip(arr, n);

    memset(dp, 0, sizeof(dp));
    memset(bracket, 0, sizeof(dp));

    for(int d=1; d<n-1; d++){
        int i=0, j=d;
        while(j<(n-1)){
            ll ans = LLONG_MAX;
            for(int k=i; k<j; k++){
                ll val = dp[i][k]+dp[k+1][j]+arr[i]*arr[k+1]*arr[j+1];
                if(ans > val){
                    ans = val;
                    bracket[i][j]=k;
                }
            }
            dp[i][j]=ans;
            i++;
            j++;
        } 
    }
    printBracket(0, n-2);
    cout<<endl;
    // cout<<dp[0][n-2]<<endl;
}

int main(){
    int t;
    cin>>t;
     while(t--){
         solve();
    }
    return 0;
}