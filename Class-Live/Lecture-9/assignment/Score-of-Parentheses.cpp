#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);

int scoreOfParentheses(string S) {
    int ans=0, open=0;

    for(int i=0; i<S.length(); i++){
        if(S[i] ==  '(') open++;
        else{
            open--;
            if(S[i-1] == '('){
                ans += (1<<open);
            }
        }
    }

    return ans;
}

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    
    return 0;
}