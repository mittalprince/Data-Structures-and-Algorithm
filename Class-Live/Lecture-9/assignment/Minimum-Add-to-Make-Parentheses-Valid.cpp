#include<iostream>
#include<vector>
#include<stack>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);

int minAddToMakeValid(string S) {
    int ans=0;
    stack<char>s;

    for(char i: S){
        if(i=='(') s.push(i);
        else{
            if(!s.empty() && s.top() == '(') s.pop();
            else s.push(i);
        }
    }

    return s.size();
}

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    
    return 0;
}