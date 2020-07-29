// https://codeforces.com/contest/1389/problem/C
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

/*
Logic: a string has both left and right shift value equal if and only if s[i]==s[(i+2)%n]

A string that have s[i]==s[i+2] have teo possiblit either all char in string are eqaul or in the form like: ababab..

So we use brute force to find all pairs (as only 0-9 digits, so total 100 combination)

And for each combination we find the max length of string that follow the above property and hence find the max of all ans
*/
ll Solve(string s, char a, char b){
    ll ct=0;
    bool flag=true;
    for(char i: s){
        if(flag){
            if(i==a){
                ct++;
                flag=!flag;
            }
        }
        else{
            if(i==b){
                ct++;
                flag=!flag;
            }
        }
    }

    if(a!=b){ // if both char are diff then string must be of even length
        if(ct&1)ct--;   
    }
    
    return ct;
}

void solve(){
    string s;
    cin>>s;
    ll n=s.length();

    ll ans=2;
    for(int i=0; i<10; i++){
        for(int j=0; j<10; j++){
            ans = max(ans, Solve(s, (char)(i+'0'), (char)(j+'0')));
        }
    }
    cout<<(n-ans)<<endl;
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