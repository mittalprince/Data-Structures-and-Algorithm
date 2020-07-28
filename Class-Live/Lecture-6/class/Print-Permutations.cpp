#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);

vector<string> arr;
void printPermutation(string input, int i){
    if(i==input.length()){
        // cout<<input<<endl;
        arr.push_back(input);
        return;
    }

    for(int j=i; j<input.length(); j++){
        swap(input[i], input[j]);
        printPermutation(input, i+1);
        swap(input[i], input[j]);
    }
}
int main(){
    string s, output;
    cin>>s;
    printPermutation(s, 0);
    // sort(arr.begin(), arr.end());
    for(string i: arr){
        cout<<i<<" ";
    }
    cout<<endl;
    return 0;
}