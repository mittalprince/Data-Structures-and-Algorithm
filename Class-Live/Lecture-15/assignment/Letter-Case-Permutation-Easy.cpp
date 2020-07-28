#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);

// using bitmasking
vector<string> letterCasePermutation(string s) {
    int n=s.length();
    map<string, bool>m;
    vector<string>ans;

    for(int i=0; i<(1<<n); i++){
        string t="";
        for(int j=0; j<n; j++){
            if(i&(1<<j)){
                t += tolower(s[j]);
            }
            else{
                t += toupper(s[j]);
            }
        }
        m[t]=true;
    }

    for(auto it: m){
        ans.push_back(it.first);
    }
    return ans;
}

// using recursion
void solve(string s, int i, vector<string>&ans){
    for(int j=i; j<s.length(); j++){
        if(s[j]>=65 && s[j]<=90){
            s[j] = s[j]+32;
            ans.push_back(s);
            solve(s, j+1, ans);
            s[j] = s[j]-32;
        }
        else if(s[j]>=97&&s[j]<=122){
            s[j] = s[j]-32;
            ans.push_back(s);
            solve(s, j+1, ans);
            s[j] = s[j]+32;
        }
    }
}

vector<string> letterCasePermutation(string S) {
    vector<string>ans;

    ans.push_back(S);
    solve(S, 0, ans);
    return ans;
}

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    
    return 0;
}