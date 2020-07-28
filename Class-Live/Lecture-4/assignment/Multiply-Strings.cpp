#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);

string multiply(string a, string b){
    int n=a.length(), m=b.length();
    if(m==0||n==0) return "0";

    int d, d1;
    string ans(n+m, '0');
    for(int i=n-1; i>=0; i--){
        d = a[i]-'0';
        for(int j=m-1; j>=0; j--){
            d1 = (b[j]-'0')*d+(ans[i+j+1]-'0');
            ans[i+j+1] = d1%10+'0';
            ans[i+j] += d1/10;
        }
    }
    int i=0;
    while(i<n+m-1 && ans[i]=='0') i++;
    return ans.substr(i);
}
int main(){
    string a, b;
    cin>>a>>b;
    string res = multiply(a, b);
    cout<<res<<endl;
    return 0;
}