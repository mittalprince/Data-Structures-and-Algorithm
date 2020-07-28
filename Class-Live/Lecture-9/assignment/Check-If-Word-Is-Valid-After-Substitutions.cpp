#include<iostream>
#include<vector>
#include<stack>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);

bool isValid(string S) {
        
    if (S.size() == 0 || S.size() % 3 != 0) {
        return false;
    }
    
    stack<char> st;
    
    for (auto c: S) {
        if (c == 'c') {
            if (st.size() < 2) {
                return false;
            }
            if (st.top() != 'b') {
                return false;
            }
            st.pop();
            if (st.top() != 'a') {
                return false;
            }
            st.pop();
        }
        else {
            st.push(c);
        }
    }
    
    return st.empty();
}

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    
    return 0;
}