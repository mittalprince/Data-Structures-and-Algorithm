#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);

vector<string> ans;

void CodesOFString(string input, string output, int i){
    if(i==input.length()){
        // cout<<output<<endl;
        ans.push_back(output);
        return;
    }

    int digit = input[i]-'0';
    output += (char)('a'+digit-1);
    CodesOFString(input, output, i+1);
    
    if((i+1) < input.length()){
        int temp = input[i+1]-'0';
        digit = digit*10 + temp;

        if(digit <= 26){
            output.pop_back();
            output += (char)('a'+digit-1);
            CodesOFString(input, output, i+2);
        }
    }
}
int main(){
    string input, output;
    cin>>input;
    CodesOFString(input, output, 0);
    cout<<"[";
    for(int i=0; i<ans.size(); i++){
        cout<<ans[i];
        if(i != ans.size()-1) cout<<", ";
    }
    cout<<"]\n";
    return 0;
}