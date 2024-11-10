#include<iostream>
#include<vector>
#include<unordered_map>
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

bool canPalindrome(unordered_map<char, int>m){
    int ct = 0;
    for(auto it: m){
        if(it.second&1) ct++;
    }
    return ct<=2;
}
string isSpecialDNASequence(const string &dna_sequence) {
    int n = dna_sequence.size();
    unordered_map<char, int> left, right;
    for(char i: dna_sequence) right[i]++;

    for(int i=1; i<n-1; i++){
        left[dna_sequence[i]]++;
        right[dna_sequence[i]]--;
        if(canPalindrome(left) && canPalindrome(right))return "YES";
    }
    return "NO";
}
int main(){

/*
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
*/

    int n;
    cin>>n;
    vector<int> arr(n);
    
    return 0;
}

/*

A DNA sequence string is considered special if it can be divided into two non-empty substrings such that the resulting strings can be rearranged to form palindromes after removing at most one character from each of them.
Given a string, dna_sequence, return the string "YES" if it is a special sequence and
"NO" otherwise. .
Note: A substring is defined as any contiguous segment of a string. A palindrome is a string that reads the same forwards and backwards such as "abba", "aba", "b", and "ccc".
Example
Suppose n = 3, and dna sequence = "abcad".


*/