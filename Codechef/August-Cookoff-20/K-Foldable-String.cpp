// https://www.codechef.com/COOK121B/problems/KFOLD
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

void solve(){
    ll n,k;
    cin>>n>>k;
    string s;
    cin>>s;

    ll freq[2]={0};
    for(char i:s){
        freq[i-'0']++;
    }

    ll grp = n/k;
    for(int i=0; i<2; i++){
        if(freq[i]%grp){
            cout<<"IMPOSSIBLE\n";
            return;
        }
    }

    ll a = freq[0]/grp;
    ll b = freq[1]/grp;

    string ans="";
    for(int i=0; i<a; i++)ans+="0";
    for(int i=0; i<b; i++)ans+="1";

    string t=ans, rt=ans;
    reverse(rt.begin(), rt.end());
    grp--;
    bool flag=true;
    while(grp--){
        if(flag){
            ans+=rt;
        }
        else ans+=t;
        flag = !flag;
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