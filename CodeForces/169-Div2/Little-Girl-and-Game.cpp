// https://codeforces.com/contest/276/problem/B
#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define debug(x) cout<<x<<"\n";
#define inf 1e9
#define INF 1e16
#define MOD 1000000007

int main(){

    // #ifndef ONLINE_JUDGE
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    // #endif

    string s;
    cin>>s;

    int freq[26]={0};
    for(char i: s){
        freq[i-'a']++;
    }

    int odd_val=0;
    for(int i=0; i<26; i++){
        if(freq[i] and freq[i]&1){
            odd_val++;
        }
    }

    if(odd_val==0){
        cout<<"First\n";
        return 0;
    }
    if(odd_val&1){
        cout<<"First\n";
    }
    else cout<<"Second\n";
    
    return 0;
}