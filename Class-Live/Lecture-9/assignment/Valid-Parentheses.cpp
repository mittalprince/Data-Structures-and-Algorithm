#include<iostream>
#include<vector>
#include<stack>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);

bool isValid(string str) {
    stack<char>s;

    for(char i: str){
        if(i == '(') s.push(')');
        else if(i == '{') s.push('}');
        else if(i == '[') s.push(']');
        else{
            if(!s.empty() && s.top() == i) s.pop();
            else return false;
        }
    }

    return s.empty();
}

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    
    return 0;
}