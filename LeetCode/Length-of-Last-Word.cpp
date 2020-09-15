// https://leetcode.com/problems/length-of-last-word/
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

int lengthOfLastWord(string s) {
    stringstream ss(s);
    string t;
    string ans;
    
    while(getline(ss, t, ' ')){
        if(t.length())ans=t;
    }
    return ans.length();

    /*
    if(s.empty()){
        return 0;
    }
    int n=s.length();
    int i=n-1;
    int len=0 ;
    while(i>=0){
        if(s[i] == ' '){
            if(len){
                break;
            }
        }
        if(s[i] != ' '){
            len++;   
        }
        i--;
    }
    return len;
    */
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