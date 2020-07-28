#include<iostream>
#include<vector>
#include<cstring>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define X 212072634227239451
#define MOD 1000000007
#define MAX 1005
#define P1 107
#define P2 1361
#define P3 10000019

ll dp[MAX][MAX][3][3][2];
ll n,m;
ll arr[MAX][MAX]={0};

void checkFactors(int &p1, int &p2, bool &p3, ll x){
    ll temp;
    if (x % P1 == 0) {
        temp = x / P1;
        p1 += (temp % P1 == 0) + 1;
        p1 = min(2, p1);
    }
    if (x % P2 == 0) {
        temp = x / P2;
        p2 += (temp % P2 == 0) + 1;
        p2 = min(2, p2);
    }
    p3 |= (x % P3 == 0);
}

ll solve(int i, int j, int p1, int p2, bool p3) {
    if (i == (n - 1) and j == (m - 1)){
        checkFactors(p1, p2, p3, arr[i][j]);
        return (p1 * p2 * p3 < 4);
    }

    if(i == n or j == m){
        return 0;
    }

    ll &ret = dp[i][j][p1][p2][p3];

    if (ret != -1)return dp[i][j][p1][p2][p3];

    checkFactors(p1, p2, p3, arr[i][j]);

    ll opt1 = solve(i+1, j, p1, p2, p3);
    ll opt2 = solve(i, j+1, p1, p2, p3);

    return ret = (opt1+opt2)%MOD;
}

int main(){
    fstIO;

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    cin>>n>>m;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>arr[i][j];
        }
    }
    memset(dp, -1, sizeof(dp));
    cout<<(solve(0,0,0,0,0))%MOD<<endl;
    return 0;
}