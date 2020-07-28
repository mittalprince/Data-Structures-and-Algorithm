#include<iostream>
#include<vector>
#include<stack>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);

// iterative
bool backspaceCompareI(string S, string T) {
    int i=S.length()-1, j=T.length()-1;
    int skipS=0, skipT=0;

    while(i>=0 || j>=0){

        while(i>=0){
            if(S[i] == '#'){
                skipS++;
                i--;
            }
            else if(skipS>0){
                skipS--;
                i--;
            }
            else break;
        }

        while(j>=0){
            if(T[j] == '#'){
                skipT++;
                j--;
            }
            else if(skipT>0){
                skipT--;
                j--;
            }
            else break;
        }

        if(i>=0 && j>=0 && S[i] != T[j]) return false;
        if(i>=0 && j<0 || j>=0 && i<0) return false;

        i--;
        j--;
    }
    return true;
}

bool backspaceCompare(string S, string T) {
    stack<char>s, t;
    for(char i: S){
        if(i=='#'){
            if(!s.empty()) s.pop();
        }
        else s.push(i);
    }

    for(char i: T){
        if(i=='#'){
            if(!t.empty()) t.pop();
        }
        else t.push(i);
    }

    while(!s.empty() && !t.empty()){
        if(s.top() != t.top()) return false;
        s.pop(); t.pop();
    }

    if(!s.empty() || !t.empty()) return false;
    return true;
}

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    
    return 0;
}