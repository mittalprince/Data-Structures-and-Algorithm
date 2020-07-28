// https://codeforces.com/contest/600/problem/C
#include<iostream>
#include<vector>
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

    string s;
    cin>>s;

    int freq[26]={0};
    for(char i: s){
        freq[i-'a']++;
    }
    vector<int>a;

    for(int i=0; i<26; i++){
        if(freq[i]&1){
            a.push_back(i);
        }
    }
    int i=0, j=a.size()-1;
    while(i<j){
        freq[a[i]]++;
        freq[a[j]]--;
        i++;
        j--;
    }
    
    string start="", rev="";
    bool odd=false;
    char ch;
    int f=0;
    for(int k=0; k<26; k++){
        if(freq[k]&1){
            odd=true;
            ch=(k+'a');
            freq[k]--;
        }
    
        for(int p=0; p<freq[k]/2; p++){
            start += (k+'a');
        }
        for(int p=0; p<freq[k]/2; p++){
            rev = char(k+'a')+rev;
        }
    
    }
    if(odd){
        start += ch;
    }
    start += rev;
    cout<<start<<endl;
    return 0;
}