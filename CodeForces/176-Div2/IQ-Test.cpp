// https://codeforces.com/contest/287/problem/A
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

bool check(char a, char b, char c, char d){
    int i=0,j=0;
    if(a=='#')i++;
    else j++;

    if(b=='#')i++;
    else j++;

    if(c=='#')i++;
    else j++;

    if(d=='#')i++;
    else j++;

    if(i==4||j==4||i==3||j==3)return true;
    return false;
}
int main(){

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    char arr[4][4];
    for(int i=0; i<4; i++){
        for(int j=0; j<4; j++){
            cin>>arr[i][j];
        }
    }
    
    for(int i=1; i<4; i++){
        for(int j=0; j<3; j++){
            char a,b,c,d;
            a=arr[i-1][j];
            b=arr[i-1][j+1];
            c=arr[i][j];
            d=arr[i][j+1];

            if(check(a,b,c,d)){
                // cout<<i<<" "<<j<<endl;
                // cout<<a<<" "<<b<<" "<<c<<" "<<d<<endl;
                cout<<"YES\n";
                return 0;
            }
        }
    }
    cout<<"NO\n";
    return 0;
    return 0;
}