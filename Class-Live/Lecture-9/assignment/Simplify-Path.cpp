#include<iostream>
#include<vector>
#include<stack>
#include<string>
#include<sstream>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);

vector<string> split(const string &s, char delin){
    vector<string>ans;
    istringstream S(s);
    string word;
    while(getline(S, word, delin)){
        ans.push_back(word);
    }
    return ans;
}

string simplifyPath(string path){
    stack<string>s;
    vector<string>words = split(path, '/');

    for(string i: words){
        if(i=="."||i=="") continue;
        else if(i == ".."){
            if(!s.empty()) s.pop();
        }
        else s.push(i);
    }

    if(s.empty()) return "/";
    string ans="";
    while(!s.empty()){
        ans = "/"+s.top()+ans;
        s.pop();
    }
    return ans;
}

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    
    return 0;
}