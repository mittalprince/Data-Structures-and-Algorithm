//https://leetcode.com/problems/longest-word-in-dictionary-through-deleting/
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

string findLongestWord(string s, vector<string>& d) {
    string ans;
    for(string word: d){ //for each word in d 
        int j=0,k=0;
        while(j<s.size() && k<word.size()){ 
            if(s[j]==word[k]) //for each letter in s and word, compare
                k++;         // & increment only if they equal
            j++;   
        }
        int n=word.size();
        if(k==n && ((ans.size()==n && ans>word) || ans.size()<n))
            ans=word;
        //save word as ans if the three conditions are met: 
            //1. k==n: if every letter of word exists in string s (and in order of the word)
            //2. ans.size()<n: word is a longer word than ans 
            //3. (ans.size()==n && ans>word): word is same size as ans but is lexicographically smaller
        //REMEMBER: "return the longest word with the smallest lexicographical order."
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