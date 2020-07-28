#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define MOD 1000000007

void solve(){
    string s;
    cin>>s;

    int zero=0, one=0;
    for(char i: s){
        if(i=='1')one++;
        else zero++;
    }

    int ans = min(one, zero);
    int c1=0, c0=0;

    for(char i: s){
        if(i=='1'){
            c1++;
            one--;
        }
        else{
            c0++;
            zero--;
        }
        ans = min(ans, min(c1+zero, c0+one));
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