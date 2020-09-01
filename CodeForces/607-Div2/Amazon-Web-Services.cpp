// https://codeforces.com/contest/1281/problem/B
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
    string s,c;
    cin>>s>>c;

    int lastIndex[26];
    for(int i=0; i<26; i++){
        lastIndex[i]=-1;
    }
    for(int i=0; i<s.length(); i++){
        lastIndex[s[i]-'A']=i;
    }

    for(int i=0, j=0; j<c.length() and i<s.length(); i++, j++){
        if(s[i]>=c[j]){
            for(int k=0; k<=c[j]-'A'; k++){
                if(lastIndex[k]>i){
                    swap(s[i], s[lastIndex[k]]);
                    if(s<c){
                        cout<<s<<endl;
                        return;
                    }
                    swap(s[i], s[lastIndex[k]]);
                }
            }
            if(s[i]>c[j]){
                cout<<"---\n";
                return;
            }
        }
        else{
            cout<<s<<endl;
            return;
        }
    }
    if(s.length()<c.length()){
        cout<<s<<endl;
        return;
    }
    cout<<"---"<<endl;
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