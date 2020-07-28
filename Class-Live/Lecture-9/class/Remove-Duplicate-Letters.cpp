#include<iostream>
#include<vector>
#include<map>
#include<stack>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);

string removeDuplicateLetters(string str){
    stack<char> s;
    int lastIndex[26]={0};
    bool present[26]={0};

    for(int i=0; i<str.length(); i++){
        lastIndex[str[i]-'a']=i;
    }

    for(int i=0; i<str.length(); i++){
        char ch=str[i];

        if(!s.empty()){
            if(!present[ch-'a']){
                while(!s.empty() && s.top()>ch && lastIndex[s.top()-'a']>i){
                    present[s.top()-'a']=false;
                    s.pop();
                }
                s.push(ch);
                present[ch-'a']=true;
            }
        }
        else{
            s.push(ch);
            present[ch-'a']=true;
        }
    }
    string ans="";
    while(!s.empty()){
        ans += s.top();
        s.pop();
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

int main(){
    string s;
    cin>>s;
    cout<<removeDuplicateLetters(s)<<endl;
    
    return 0;
}