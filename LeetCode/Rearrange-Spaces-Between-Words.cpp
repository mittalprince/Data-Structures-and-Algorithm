// https://leetcode.com/problems/rearrange-spaces-between-words/
#include<iostream>
#include<vector>
#include<sstream>
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

string reorderSpaces(string text) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int space_ct=0;
    for(char i:text)space_ct += i==' ';

    stringstream ss(text);
    string s;

    vector<string>words;

    while(ss >> s){
        words.push_back(s);
    }

    int n=words.size();
    int ct = n>1?space_ct/(n-1):0;

    string ans=words[0];
    for(int i=1; i<n; i++){
        ans += string(ct, ' ');
        ans += words[i];
    }

    if(space_ct-(ct*(n-1))>0){
        ans += string(space_ct-(ct*(n-1)), ' ');
    }

    return ans;
}

int main(){

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    int n;
    cin>>n;
    vector<int> arr(n);
    
    return 0;
}