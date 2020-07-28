#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define MAX 10000000
ll table[MAX];

void buildResetTable(string pattern)
{
    ll i = 1, j = 0;
    ll len = pattern.length();
    while (i < len)
    {
        while (j > 0 && pattern[i] != pattern[j])
        {
            j = table[j - 1];
        }
        if (pattern[i] == pattern[j])
        {
            table[i] = j + 1;
            i++;
            j++;
        }
        else
        {
            if (j == 0)
                i++;
        }
    }
}
void solve(){
    string text;
    cin>>text;
    string pattern = "bear";
    ll lp = pattern.length();
    ll lt = text.length();
    
    buildResetTable(pattern);
    ll i = 0, j = 0;
    vector<ll> pos;
    while (i < lt){
        while (j > 0 && pattern[j] != text[i]){
            j = table[j - 1];
        }
        if (pattern[j] == text[i]){
            i++;
            j++;
        }
        else
            i++;
        if (j == lp){
            // cout << i - lp << endl;
            pos.push_back(i-lp);
            j = table[j - 1];
        }
    }
    ll ans = 0;
    for(int i=0; i<pos.size(); i++){
        if(i==0){
            ans += (lt-(pos[i]+3))*(pos[i]+1);
        }
        else{
            ans += (lt-(pos[i]+3))*(pos[i]-pos[i-1]);
        }
    }

    cout<<ans<<endl;
}

bool check(int j, string s){
    if(s[j]=='r' && s[j-1]=='a'&& s[j-2]=='e' && s[j-3]=='b') return true;
    return false;
}
void Solve(){
    string s;
    cin>>s;
    ll n= s.length();
    ll ans=0;
    int start=0;
    for(int j=3; j<n; j++){
        if(check(j, s)){
            ans += (n-j)*(j-3-start+1);
            start = j-2;
        }
    }
    cout<<ans<<endl;
}
int main()
{
    int t;
    cin>>t;
    while(t--){
        //using KMP
        // solve();
        Solve();
    }
    return 0;
}