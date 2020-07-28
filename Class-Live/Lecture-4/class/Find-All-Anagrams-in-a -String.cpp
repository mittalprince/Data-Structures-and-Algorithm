#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);

bool compare(vector<int>& txt, vector<int>& pat){
    for(int i=0; i<26; i++){
        if(txt[i] ^ pat[i]) return false;
    }
    return true;
}

vector<int> findAnagrams(string text, string pattern){
    vector<int> txt(26, 0), pat(26, 0);
    int lp = pattern.length();
    int ls = text.length();

    vector<int> ans;
    if(lp>ls) return ans;
    for(int i=0; i<lp; i++){
        pat[pattern[i]-'a']++;
        txt[text[i]-'a']++;
    }
    int i;
    for(i=0; i<ls-lp; i++){
        if(compare(txt, pat)) ans.push_back(i);
        txt[text[i]-'a']--;
        txt[text[i+lp]-'a']++;
    }
    if(compare(pat, txt)) ans.push_back(i);
    return ans;
}

int main(){
    string text, pattern;
    cin>>text>>pattern;

    vector<int> res = findAnagrams(text, pattern);
    for(int i: res) cout<<i<<" ";
    cout<<endl;
    return 0;
}