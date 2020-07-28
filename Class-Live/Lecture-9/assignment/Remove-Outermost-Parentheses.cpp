#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);

string removeOuterParentheses(string S) {
    int sum=0, tail=0;
    string str;
    for (int i =0;i<S.size();i++){
        S[i]=='(' ? sum++ : sum--;
        if (sum==0){
            str.append(S,tail+1,i-tail-1);
            tail=i+1;
            sum=0;
        } 
    }
    return str;
}

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    
    return 0;
}