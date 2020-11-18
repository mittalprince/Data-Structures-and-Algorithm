//https://leetcode.com/problems/determine-if-two-strings-are-close/
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

bool closeStrings(string word1, string word2) {
    int a1[26]={0}, a2[26]={0};

    if(word1.length() != word2.length())return false;

    for(int i=0; i<word1.length(); i++){
        a1[word1[i]-'a']++;
        a2[word2[i]-'a']++;
    }

    bool same=true;
    for(int i=0; i<26; i++){
        if(a1[i] and a2[i]==0){
            same=false;
            break;
        }
        if(a2[i] and a1[i]==0){
            same=false;
            break;
        }
    }

    sort(a1, a1+26);
    sort(a2, a2+26);

    for(int i=0; i<26; i++){
        if(a1[i]!=a2[i]){
            same=false;
            break;
        }
    }
    return same;
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