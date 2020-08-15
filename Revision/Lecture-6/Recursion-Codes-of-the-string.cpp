// https://hack.codingblocks.com/app/contests/1496/145/problem
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

string s;
vector<string>arr;

void solve(int i, string t){
    if(i==s.length()){
        arr.push_back(t);
        return;
    }
    int digit=s[i]-'0';
    t += (char)('a'+digit-1);
    solve(i+1, t);

    if((i+1)<s.length()){
        int temp = s[i+1]-'0';
        digit = digit*10+temp;
        if(digit<=26){
            t.pop_back();
            t += (char)('a'+digit-1);
            solve(i+2, t);
        }
    }
}

int main(){

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    cin>>s;
    solve(0, "");
    cout<<"[";
    for(int i=0; i<arr.size(); i++){
        cout<<arr[i];
        if(i != arr.size()-1) cout<<", ";
    }
    cout<<"]\n";
    
    return 0;
}