#include<iostream>
#include<climits>
#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    while(t--){
        string s;
        bool freq[26]={0};
        cin>>s;
        for(int i=0; i<s.length(); i++){
            int j=i;
            while(j+1<s.length() && s[j+1] == s[i]){
                j++;
            }
            if(!((j-i)&1)){
                freq[s[i]-'a']=1;
            }
            i=j;
        }
        for(int i=0; i<26; i++){
            if(freq[i]) cout<<char('a'+i);
        }
        cout<<endl;
    }
}