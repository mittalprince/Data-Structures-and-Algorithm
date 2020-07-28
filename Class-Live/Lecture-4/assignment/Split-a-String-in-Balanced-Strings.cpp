#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);

int balancedStringSplit(string s){
    int n=s.length();
    int l=0, r=0;
    int ans=0;
    for(char i: s){
        (i=='L')?l++:r++;
        if(l==r){
            ans++;
        }
    }
    return ans;
}
int main(){
    string s;
    cin>>s;
    cout<<balancedStringSplit(s)<<endl;
    return 0;
}