// https://codeforces.com/contest/861/problem/C
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
    int idx=0;
    int n=s.length();

    for(int i=0; i<s.length();){
        int ct=0, unique=0;
        bool freq[26]={0};
        int j=i;
        string t="";
        while(j<n){
            if(s[j]!='a' and s[j]!='e' and s[j]!='i' and s[j]!='o' and s[j]!='u'){
                if(!freq[s[j]-'a'])freq[s[j]-'a']=1, unique++;
                ct++;
            }
            else{
                ct=0,unique=0;
                for(int k=0; k<26; k++)freq[k]=0;
            }

            if(ct>2 and unique>1)break;
            t += s[j++];
        }
        cout<<t<<" ";
        i=j;
    }
    cout<<endl;
}

int main(){

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    int t=1;
    // cin>>t;
    while(t--){
        solve();
    }
    return 0;
}