#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);

bool checkObedientString(string s, int i, int n){
    if(i==s.length()){
        return true;
    }
    if(i==0){
        if(s[i]!='a') return false;
    }

    if(s[i] == 'a'){
        if(i+1 < n){
            if(s[i+1] == 'a'){
                return checkObedientString(s, i+2, n);
            }
            else{
                if(i+2<n && s[i+2] == 'b'){
                    if(i+3<n && s[i+3] != 'a') return false;
                    return checkObedientString(s, i+3, n);
                }
                else return false;
            }
        }
        return true;
    }

    if(i+1<n && s[i+1] == 'b'){
        if(i+2<n && s[i+2] != 'a') return false;
        return checkObedientString(s, i+2, n);
    }

    return false;
}

bool CheckString(string s, int i ,int n){
    if(i==n) return true;

    if(i==0 && s[i] != 'a') return false;

    if(s[i] == 'a'){
        if(!(s[i+1]=='\0'||(s[i+1]=='b'&& s[i+2]=='b') || (s[i+1]=='a')))
		    return false;
    }
    else{
        if(s[i+1] == '\0' || s[i+1] == 'a') return false;
        if(!(s[i+2]=='\0' || s[i+2] == 'a')) return false;
        i++;
    }

    return CheckString(s, i+1, n);
}

int main(){
    string s;
    cin>>s;
    // if(checkObedientString(s, 0, s.length())) cout<<"true\n";
    // else cout<<"false\n";
    if(CheckString(s, 0, s.length())) cout<<"true\n";
    else cout<<"false\n";
    return 0;
}