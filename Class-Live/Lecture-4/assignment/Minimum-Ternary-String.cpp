#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);

bool compare(char a, char b){
    int A = a-'0', B = b-'0';
    if(abs(A-B) == 1 || abs(A-B) == 0){
        return A<=B;
    }
    return false;
}
void solve(){
    string s;
    cin>>s;
    // sort(s.begin(), s.end(), compare);
    // cout<<s<<endl;

    // logic since 1 is consecutive of 0 and 2 so we can place to any position
    // so we just ct freq of 1
    // while counting 1 we also make ans string and add char as it as in ans if its not 1 (next line why)
    // since we have to make smallest, and we can only have option to place 1 any pos
    // now we have ans string which contain onlu 0 & 2, now we move our pointer to forward till we have 
    // continuos 0, then we insert our 1 ct times.

    ll one_ct=0;
    string ans="";
    for(int i=0; i<s.length(); i++){
        if(s[i] == '1') one_ct++;
        else ans += s[i];
    } 
    ll pos=0;
    while(pos<s.length() && ans[pos] == '0') pos++;

    ans.insert(pos, one_ct, '1');
    cout<<ans<<endl;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}