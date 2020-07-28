// https://codeforces.com/contest/975/problem/A
#include<iostream>
#include<vector>
#include<set>
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

    int n;
    cin>>n;
    set<string>s;
    for(int i=0; i<n; i++){
        string t;
        cin>>t;
        int freq[26]={0};
        string temp="";
        for(int i=0; i<t.length(); i++){
            freq[t[i]-'a']++;
        }
        for(int i=0; i<26; i++){
            if(freq[i]){
                temp += (i+'a');
            }
        }
        s.insert(temp);
        // cout<<temp<<endl;
    }
    cout<<s.size()<<endl;
    return 0;
}