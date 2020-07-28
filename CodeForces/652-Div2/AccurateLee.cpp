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
    int n;
    string s;
    cin>>n>>s;
    string ans="";
    int i=0;
    while(i<n and s[i] == '0'){
        ans += s[i++];
    }
    vector<char>t;
    int ct=0;
    char ch;
    for(; i<n;){
        ch = s[i];
        ct=0;
        while(i<n and s[i]==ch){
            ct++;
            i++;
        }
        // cout<<ch<<endl;
        t.push_back(ch);
    }
    if(t.empty() or t.size()==1){
        cout<<s<<endl;
        return;
    }
    // cout<<"Size "<<t.size()<<endl;
    ans += "0";
    if(t.size()&1){
        for(int k=0; k<ct; k++){
            ans += "1";
        }
    }
    cout<<ans<<endl;
    return;
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