#include<iostream>
#include<vector>
#include<stack>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);

string removeDuplicates(string S) {
    stack<char>s;

    for(char i: S){
        bool f=true;
        while(!s.empty() && s.top()==i) {
            s.pop();
            f=false;
        }
        if(f) s.push(i);
    }

    string ans="";
    while(!s.empty()){
        ans = s.top()+ans;
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