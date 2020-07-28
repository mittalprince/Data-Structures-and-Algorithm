// https://codeforces.com/contest/1304/problem/B
#include<iostream>
#include<vector>
#include<unordered_map>
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

int main(){

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    int n,M;
    cin>>n>>M;
    unordered_map<string, bool>m;
    unordered_map<string, int>ct;

    vector<string>arr(n);
    for(int i=0; i<n; i++){
        cin>>arr[i];
        m[arr[i]]=true;
    }
    int len=0;
    vector<string>a,b;
    for(int i=0; i<n; i++){
        string s = arr[i];
        string t = s;
        reverse(t.begin(), t.end());
        if(t!=s){
            if(m[t]){
                len += 2;
                a.push_back(s);
                b.push_back(t);
                m[s]=false;
                m[t]=false;
            }
        }
        else{
            ct[t]++;
        }
    }
    int mx=0;
    string mx_s;
    for(auto it: ct){
        if(it.second>mx){
            mx=it.second;
            mx_s = it.first;
        }
    }
    len += mx;
    cout<<len*M<<endl;
    while(mx--){
        a.push_back(mx_s);
    }
    reverse(b.begin(), b.end());
    a.insert(a.end(), b.begin(), b.end());
    for(string i: a){
        cout<<i;
    }
    cout<<endl;
    return 0;
}