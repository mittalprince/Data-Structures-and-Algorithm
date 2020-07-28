#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);

vector<char> state;

bool check(string s, int i){
    if(i == s.length()){
        return state.empty(); 
    } 

    if(s[i] == '(' || s[i] == '[' || s[i] == '{') state.push_back(s[i]);
    else if(s[i] == ')' || s[i] == ']' || s[i] == '}'){
        if(state.empty()) return false;

        if(s[i] == ']' && state.back() != '[') return false; 
        if(s[i] == '}' && state.back() != '{') return false; 
        if(s[i] == ')' && state.back() != '(') return false; 

        state.pop_back();
    }
    return check(s, i+1);
}
int main(){
    string s;
    cin>>s;
    // check(s, 0);
    if(check(s, 0)){
        cout<<"true\n";
    }
    else cout<<"false\n";
    return 0;
}