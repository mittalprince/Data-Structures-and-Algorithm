#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);

bool compare(int pat[], int txt[]){
    for(int i=0; i<26; i++){
        if(pat[i] != txt[i]) return false;
    }
    return true;
}
bool checkInclusion(string s1, string s2){
    int lp = s1.length(), lt = s2.length();

    if(lt<lp) return false;
    int pat[26]={0}, txt[26]={0};

    for(int i=0; i<lp; i++){
        pat[s1[i]-'a']++;
        txt[s2[i]-'a']++;
    }

    for(int i=0; i<lt-lp; i++){
        if(compare(txt, pat)) return true;
        txt[s2[i+lp]-'a']++;
        txt[s2[i]-'a']--;
    }
    return compare(txt, pat);
}

int main(){
    string s1, s2;
    cin>>s1>>s2;
    if(checkInclusion(s1, s2)) cout<<"True\n";
    else cout<<"False\n";
    return 0;
}