#include<iostream>
#include<vector>
#include<set>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);

set<string>S;

void findPerm(string s, int i){
    if(i==s.length()){
        S.insert(s);
        return;
    }
    for(int k=i; k<s.length(); k++){
        swap(s[i], s[k]);
        findPerm(s, i+1);
        swap(s[i], s[k]);
    }
}
int main(){
    string s;
    cin>>s;
    findPerm(s, 0);
    for(auto it: S){
        cout<<it<<endl;
    }
    return 0;
}