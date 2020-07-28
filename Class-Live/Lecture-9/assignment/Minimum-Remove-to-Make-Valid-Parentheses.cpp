#include<iostream>
#include<vector>
#include<stack>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);

string minRemoveToMakeValid(string S) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    stack<int>s;

    for(int i=0; i<S.length(); i++){

        if(S[i] == '(') s.push(i);
        if(S[i] == ')'){
            if(s.empty()){
                S[i] = 'A';
                continue;
            }
            s.pop();
        }
    }

    while(!s.empty()){
        int t = s.top();
        s.pop();
        S[t]='A';
    }

    S.erase(remove(S.begin(), S.end(), 'A'), S.end());
    return S;
}

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    
    return 0;
}