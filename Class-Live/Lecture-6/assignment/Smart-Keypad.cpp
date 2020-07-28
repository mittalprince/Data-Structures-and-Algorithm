#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);

char phone[][10] = {" ", ".+@$", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

void PhoneKeypad(string input, string output, int i){
    if(i==input.length()){
        cout<<output<<" ";
        return;
    }

    int idx = input[i]-'0';
    for(int k=0; k<strlen(phone[idx]); k++){
        output += phone[idx][k];
        PhoneKeypad(input, output, i+1);
        output.pop_back();
    }
}

int main(){
    string input, output;
    cin>>input;
    PhoneKeypad(input, output, 0);
    cout<<endl;
    return 0;
}