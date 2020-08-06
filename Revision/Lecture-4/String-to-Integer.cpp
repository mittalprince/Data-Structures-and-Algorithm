// https://leetcode.com/problems/string-to-integer-atoi/
#include<iostream>
#include<vector>
#include<climits>
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

int myAtoi(string str) {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int n=str.length();
    int i=0;

    while(i<n and str[i]==' ')i++;
    if(i>=n){
        return 0;
    }

    bool positive=true;

    if(str[i] == '-'||str[i]=='+'){
        positive = !(str[i]=='-');
        i++;
    }

    while(i<n and str[i] == '0')i++;


    long long ans=0;
    while(i<n and str[i]>='0' and str[i]<='9'){
        ans = ans*10 + (str[i]-'0');
        if(ans>INT_MAX or ans<INT_MIN){
            return positive?INT_MAX:INT_MIN;
        }
        i++;
    }
    if(!positive)ans *= -1;
    if(ans>INT_MAX or ans<INT_MIN){
        return positive?INT_MAX:INT_MIN;
    }

    return ans;
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