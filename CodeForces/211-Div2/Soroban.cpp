// https://codeforces.com/contest/363/problem/A
#include<iostream>
#include<vector>
#include<algorithm>
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

int main(){

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    string s;
    cin>>s;
    reverse(s.begin(), s.end());
    
    for(int i=0; i<s.length(); i++){
        int val = s[i]-'0';
        if(val>4){
            cout<<"-O|";
            val -= 5;
        }
        else{
            cout<<"O-|";
        }
        for(int i=0; i<val; i++){
            cout<<"O";
        }
        cout<<"-";
        for(int i=val; i<4; i++){
            cout<<"O";
        }
        cout<<endl;
    }
    return 0;
}