// https://codeforces.com/contest/59/problem/C
#include<iostream>
#include<vector>
#include<map>
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
    int k;
    cin>>k;
    k--;

    string s;
    cin>>s;

    int i=0, j=s.length()-1;
    bool freq[26]={0};

    while(i<j){
        if(s[i] == s[j]){
            if(s[i] != '?')freq[s[i]-'a']=true;
        }
        else{
            if(s[i] == '?'){
                s[i] = s[j];
                freq[s[i]-'a']=true;
            }
            else if(s[j] == '?'){
                s[j]=s[i];
                freq[s[i]-'a']=true;
            }
            else{
                cout<<"IMPOSSIBLE\n";
                return;
            }
        }
        i++; j--;
    }

    if(i==j and s[i] != '?'){
        freq[s[i]-'a']=true;
    }

    while(i>=0){
        while(k>0 and freq[k])k--;
        if(s[i] == s[j] and s[i] == '?'){
            s[i] = s[j] = (char)(k+'a');
            freq[k]=true;
        }
        i--;
        j++;
    }

    if(k==0 and freq[k]){
        cout<<s<<endl;
    }    
    else cout<<"IMPOSSIBLE\n";
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