// https://hack.codingblocks.com/app/contests/1496/506/problem
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

string s;
int n;

bool solve(int i){
    if(i>=n){
        return true;
    }
    if(s[0] != 'a')return false;

    if(s[i]=='a'){
        if(s[i+1]=='a' or (s[i+1]=='b' and s[i+2]=='b') or s[i+1]=='\0'){
            return solve(i+1);
        }
        return false;
    }
    if(s[i]=='b' and s[i+1]=='b'){
        if(s[i+2]=='a' or s[i+2]=='\0'){
            return solve(i+2);
        }
        return false;
    }
    return false;
}

int main(){

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    cin>>s;
    n = s.length();
    if(solve(0)){
        cout<<"true\n";
    }
    else cout<<"false\n";
    
    return 0;
}