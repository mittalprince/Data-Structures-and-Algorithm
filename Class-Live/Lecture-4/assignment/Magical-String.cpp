#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);

int magicalString(int n){
    string ans="";
    ans +="1";
    ans +="2";
    ans +="2";
    int i=2;
    int curr=1;
    while(i<n){
        if(ans[i]=='2'){
            ans += curr+'0';
            ans += curr+'0';
        }
        else ans += curr+'0';
        curr = (curr==2)?1:2;
        i++;
    }
    int ct=0;
    for(int j=0; j<n; j++){
        if(ans[j]=='1') ct++;
    }
    return ct;
}
int main(){
    int n;
    cin>>n;
    cout<<magicalString(n)<<endl;
    return 0;
}