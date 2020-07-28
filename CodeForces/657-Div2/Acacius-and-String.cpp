// https://codeforces.com/contest/1379/problem/A
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

bool check(string s, string t){
    int ct=0;
    int n=s.length();
    for(int i=0; i<n-6; i++){
        string a=s.substr(i, 7);
        if(a==t){
            ct++;
        }
        if(ct>1){
            return false;
        }
    }
    return ct==1;
}
void solve(){
    int n;
    cin>>n;
    string s;
    cin>>s;

    string t = "abacaba";

    if(n<t.length()){
        cout<<"No\n";
        return;
    }

    if(s==t){
        cout<<"Yes\n";
        cout<<s<<endl;
        return;
    }

    int ct=0;
    for(int i=0; i<n-6; i++){
        string a=s.substr(i, 7);
        if(a==t){
            ct++;
        }
        if(ct>1){
            cout<<"No\n";
            return;
        }
    }
    
    if(ct==1){
        cout<<"Yes\n";
        for(char i: s){
            if(i=='?')i='e';
            cout<<i;
        }
        cout<<endl;
        return;
    }

    for(int i=0; i<n-6; i++){
        string original = s;
        string a = s.substr(i, 7);
        bool exist=true, question=false;

        for(int j=0; j<t.length(); j++){
            if(a[j]==t[j])continue;
            else if(a[j]=='?' and ct==0){
                original[i+j] = t[j];
            }
            else exist=false;
        }
        
        if(exist and check(original, t)){
            cout<<"Yes\n";
            for(char i: original){
                if(i=='?')i='e';
                cout<<i;
            }
            cout<<endl;
            return;
        };
    }

    
    cout<<"No\n";
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