// https://www.hackerearth.com/practice/basic-programming/implementation/basics-of-implementation/practice-problems/algorithm/find-the-vaccine-a60e06ee/submissions/
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


int main(){

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    int n;
    cin>>n;
    
    int len;
    cin>>len;
    string s;
    cin>>s;
    int g=0, c=0;
    for(char i: s){
        if(i=='G')g++;
        if(i=='C')c++;
    }

    ll ans=0, idx=1;
    for(int i=0; i<n; i++){
        cin>>len;
        cin>>s;
        ll curr_ans=0;
        for(char i: s){
            if(i=='G')curr_ans += c;
            else if(i=='C') curr_ans += g;
        }
        if(ans<curr_ans){
            ans = curr_ans;
            idx = i+1;
        }
    }
    cout<<idx<<endl;
    return 0;
}