// https://leetcode.com/problems/multiply-strings/
#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define ip1(arr, n) for(int i=1; i<=n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define debug(x) cout<<x<<"\n";
#define inf 1e9
#define INF 1e16
#define MOD 1000000007

string multiply(string num1, string num2) {
    int n=num1.length(), m=num2.length();
    if(m==0||n==0) return "0";

    int d, d1;
    string ans(n+m, '0');

    for(int i=n-1; i>=0; i--){
        d = num1[i]-'0';
        for(int j=m-1; j>=0; j--){
            d1 = (num2[j]-'0')*d + ans[i+j+1]-'0';
            ans[i+j+1] = d1%10 + '0';
            ans[i+j] += d1/10;
        }
    }
    int i=0;
    while(i<n+m-1 and ans[i] == '0')i++;
    return ans.substr(i);
}

int main(){

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    int n;
    cin>>n;
    vector<int> arr(n);
    
    return 0;
}