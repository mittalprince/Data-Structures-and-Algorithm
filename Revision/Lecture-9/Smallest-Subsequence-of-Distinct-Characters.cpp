// https://leetcode.com/problems/smallest-subsequence-of-distinct-characters/
// https://leetcode.com/problems/remove-duplicate-letters/
#include<iostream>
#include<vector>
#include<stack>
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

string removeDuplicateLetters(string text) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int lastIndex[26];
    for(int i=0; i<text.length(); i++){
        lastIndex[text[i]-'a']=i;
    }

    stack<char>s;
    bool isPresent[26]={0};

    for(int i=0; i<text.length(); i++){
        if(!isPresent[text[i]-'a']){
            while(!s.empty() and text[i]<s.top() and i<lastIndex[s.top()-'a']){
                isPresent[s.top()-'a']=false;
                s.pop();
            }
            s.push(text[i]);
            isPresent[text[i]-'a']=true;
        }
    }

    string ans="";
    while(!s.empty()){
        ans += s.top();
        s.pop();
    }
    std::reverse(ans.begin(), ans.end());
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