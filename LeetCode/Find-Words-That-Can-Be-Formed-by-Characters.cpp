//https://leetcode.com/problems/find-words-that-can-be-formed-by-characters/
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

int countCharacters(vector<string>& words, string chars) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int arr[26]={0};
    for(char i: chars){
        arr[i-'a']++;
    }

    int ans=0;
    for(string word: words){
        int t[26];
        for(int i=0; i<26; i++)t[i]=arr[i];
        bool exist=true;
        for(char i: word){
            t[i-'a']--;
            if(t[i-'a']<0){
                exist=false;
                break;
            }
        }
        if(exist){
            ans += word.length();
        }
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