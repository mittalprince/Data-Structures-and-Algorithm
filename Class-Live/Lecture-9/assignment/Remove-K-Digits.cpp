#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);

string removeKdigits(string num, int k) {
    string ans="";

    for(char i: num){
        while(!ans.empty() && ans.back() > i && k){
            ans.pop_back();
            k--;
        }
        if(ans.size() || i != '0') ans.push_back(i);
    }

    while(ans.size() && k--){
        ans.pop_back();
    }
    return ans.empty()?"0":ans;
}

int main(){
    string s;
    cin>>s;
    int k;
    cin>>k;
    cout<<removeKdigits(s, k)<<endl;
    return 0;
}