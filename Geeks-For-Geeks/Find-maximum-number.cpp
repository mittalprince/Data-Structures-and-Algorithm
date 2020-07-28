#include<iostream>
#include<map>
using namespace std;

void solve(){
    string s;
    cin>>s;
    
    map<int, int>m;
    
    for(char i: s){
        m[i-'0']++;
    }
    s = "";
    for(int i=9; i>=0;){
        if(m[i] > 0){
            s += (i+'0');
            m[i]--;
        }
        else i--;
    }
    cout<<s<<endl;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}