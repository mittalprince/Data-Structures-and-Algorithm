#include<iostream>
#include<vector>
#include<stack>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);

string reverseParentheses(string str) {
    stack<string>s;

    for(int i=0; i<str.length();){
        if(str[i] == '('){
            s.push("(");
            i++;
        }
        else if(str[i] == ')'){
            string x="";
            while(!s.empty() && s.top() != "("){
                x = s.top()+x;
                s.pop();
            }
            if(!s.empty() && s.top() == "(") s.pop();
            if(!x.empty()){
                reverse(x.begin(), x.end());
                // cout<<"pop "<<x<<endl;
                s.push(x);
            }
            i++;
        }
        else{
            string x="";
            while(i<str.length() && str[i] != '(' && str[i] != ')'){
                x += str[i++];
            }
            // cout<<"push "<<x<<endl;
            s.push(x);
        }
    }

    string ans="";
    while(!s.empty()){
        ans = s.top() +ans;
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