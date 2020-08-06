// https://leetcode.com/problems/reverse-words-in-a-string-iii/
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

void reverse(int s, int e, string& S){
    while(s<e){
        swap(S[s], S[e]);
        s++;
        e--;
    }
    return;
}

string reverseWords(string s) {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n=s.length();

    for(int i=0; i<n;){
        if(s[i] == ' '){
            i++;
            continue;
        }
        int j=i+1;
        while(j<n && s[j] != ' ') j++;
        if(j-i > 1) reverse(i, j-1, s);
        i=j;
    }
    return s;
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