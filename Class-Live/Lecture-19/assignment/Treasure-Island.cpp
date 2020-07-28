// Treasure Island
#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define debug(x) cout<<x<<"\n";
#define MOD 1000000007

/*
Logic: Used Rec to find whether there exist any path from src to dest.

The key observation is the ans cam be upto 2. By observing 3 test case, u can
easliy understand we can block arr[0][1] & arr[1][0] aso that he can move.

So first check if pth exist or not. If not then we do nothing and print 0
otherwise, we mark all cell visited which in one path from src to dest. Now we again check
if there is still some path then we must block arr[0][1] & arr[1][0], so ans will be 2
otherwise ans will be 1.
*/

ll n,m;
vector<vector<bool> >arr;

bool solve(ll i, ll j){
    if(i>=n || j>=m || !arr[i][j])return false;

    if(i==n-1 && j==m-1)return true;

    arr[i][j]=false;

    if(solve(i+1, j) || solve(i, j+1))return true;
    return false;
}

int main(){
    fstIO;
    
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    cin>>n>>m;
    arr = vector<vector<bool> >(n, vector<bool>(m, false));

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            char ch;
            cin>>ch;
            arr[i][j] = (ch=='.');
        }
    }

    ll ans=0;
    ll path_exist = solve(0, 0);
    if(!path_exist){
        cout<<"0\n";
    }
    else{
        ans++;
        arr[0][0]=true;
        arr[n-1][m-1]=true;

        path_exist = solve(0,0);
        if(path_exist){
            ans++;
            cout<<ans<<endl;
        }
        else cout<<ans<<endl;

    }
    return 0;
}