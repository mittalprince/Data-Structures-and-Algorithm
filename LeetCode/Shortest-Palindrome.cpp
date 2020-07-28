#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);
/*
Given a string s, you are allowed to convert it to a palindrome by adding characters in front of it. 
Find and return the shortest palindrome you can find by performing this transformation.
*/

// use KMP resetTable Logic
// concat (original string) + $ + (rev of origibnal string)
// find longest prefix which is also suffix 
// append rev.substr(0, n-lps[n-1]) + 
 
int buildResetTable(string pattern){
    int i=1, j=0;
    int len = pattern.length();
    int table[1000000]={0};

    while(i<len){
        while(j>0 && pattern[i] != pattern[j]){
            j=table[j-1];
        }
        if(pattern[i] == pattern[j]){
            table[i]=j+1;
            i++;
            j++;
        }
        else{
            if(j==0) {
                table[i]=0;
                i++;
            }
        }
    }
    return table[len-1];
}

string shortestPalindrome(string s) {
    string rev = s;
    reverse(rev.begin(), rev.end());
    string t = s+"#"+rev;

    int prefixLen = buildResetTable(t);
    cout<<prefixLen<<endl;
    return rev.substr(0, s.length()-prefixLen) + s;
}

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    
    return 0;
}