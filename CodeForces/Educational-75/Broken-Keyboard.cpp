// https://codeforces.com/contest/1251/problem/A
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
    // cout<<s<<endl;
    bool freq[26]={0};

    for(int i=0; i<s.length(); i++){
        int j=i;
        while(j+1<s.length() && s[j+1]==s[i]){
            j++;
        }
        if(!((j-i)&1)){
            freq[s[i]-'a']=1;
        }
        i=j;
    }

    for(int i=0; i<26; i++){
        if(freq[i])cout<<char(i+'a');
    }
    cout<<endl;
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