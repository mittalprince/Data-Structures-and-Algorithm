#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);

string s;

int main(){
    cin>>s;
    
    for(int i=0; i<(1<<s.length()); i++){
        string ans="";
        for(int j=0; j<s.length(); j++){
            if(i&(1<<j)){
                ans += s[j];
            }
        }
        cout<<ans<<" ";
    }
    cout<<endl<<(1<<s.length())<<endl;
    return 0;
}