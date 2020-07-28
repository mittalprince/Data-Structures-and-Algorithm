// https://codeforces.com/contest/600/problem/A
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

bool check(string s){
    if(s.empty())return false;
    for(int i=0; i<s.length(); i++){
        if((s[i]-'0')<0 or (s[i]-'0')>9)return false;
    }
    if(s[0]=='0' and s.length()>1)return false;
    return true;
}

int main(){

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    string s, curr="";
    cin>>s;

    vector<string>lis;
    for(int i=0; i<s.length(); i++){
        if(s[i]==';' or s[i]==','){
            lis.push_back(curr);
            curr ="";
        }
        else{
            curr += s[i];
        }
    }
    lis.push_back(curr);
    vector<string>a,b;
    for(int i=0; i<lis.size(); i++){
        if(check(lis[i])){
            a.push_back(lis[i]);
        }
        else b.push_back(lis[i]);
    }
    if(a.empty()){
        cout<<"-\n";
    }
    else{
        cout<<"\"";
        for(int i=0; i<a.size(); i++){
            if(i<a.size()-1)cout<<a[i]<<",";
            else cout<<a[i];
        }
        if(a.empty())cout<<"-";
        cout<<"\"";
        cout<<endl;
    }

    if(b.empty()){
        cout<<"-\n";
    }
    else{
        cout<<"\"";
        for(int i=0; i<b.size(); i++){
            if(i<b.size()-1)cout<<b[i]<<",";
            else cout<<b[i];
        }
        cout<<"\"";
    }
    return 0;
}