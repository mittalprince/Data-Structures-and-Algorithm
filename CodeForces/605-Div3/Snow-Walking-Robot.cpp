// https://codeforces.com/contest/1272/problem/B
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

void solve(){
    string s;
    cin>>s;

    int l=0, r=0, t=0, d=0;
    for(char i: s){
        if(i=='L')l++;
        else if(i=='R')r++;
        else if(i=='U')t++;
        else d++;
    }

    int x = min(l,r);
    l=x, r=x;
    int y = min(t,d);
    t=y, d=y;

    if(x==0){
        cout<<min(2*y,2)<<endl;
        if(y>=1){
            cout<<"UD\n";
        }
        return;
    }
    if(y==0){
        cout<<min(2*x,2)<<endl;
        if(x>=1){
            cout<<"LR\n";
        }
        return;
    }
    cout<<2*x+2*y<<endl;
    
    string left(l, 'L');
    string right(r, 'R');
    string up(t, 'U');
    string down(d, 'D');
    cout<<left<<up<<right<<down;
    cout<<endl;
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