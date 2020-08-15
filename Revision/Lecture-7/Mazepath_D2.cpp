// https://hack.codingblocks.com/app/contests/1496/447/problem
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
int ans=0;

bool isValid(int i, int j){
    return (i>=0 and i<n and j>=0 and j<m);
}

void solve(int i, int j, string t){
    if(i==(n-1) and j==(m-1)){
        ans++;
        cout<<t<<" ";
        return;
    }
    if(isValid(i,j)){
        t+="V";
        solve(i+1, j, t);
        t.pop_back();
        t+="H";
        solve(i,j+1,t);
        t.pop_back();
        if(i==j or (i+j == (n-1))){
            t+="D";
            solve(i+1, j+1, t);
        }
    }
}
int main(){
	
    cin>>n;
    m=n;
    solve(0,0,"");
    cout<<endl<<ans<<endl;
    return 0;
}