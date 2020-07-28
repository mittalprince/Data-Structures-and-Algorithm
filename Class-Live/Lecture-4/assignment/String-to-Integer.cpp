#include<iostream>
#include<vector>
#include<climits>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);

int myAtoi(string s){
    int n=s.length();
    int i=0;

    while(i<n && s[i] == ' ') i++;
    if(i>=n) return 0;

    bool pos=true;
    if(s[i] == '-' || s[i] == '+'){
        if(s[i]=='-') pos=false;
        i++;
    }
    while(i<n && s[i] == '0') i++;
    int start=i;
    while(i<n && s[i]>='0' && s[i]<= '9') i++;
    int end = i-1;

    if(end-start+1>10){
        if(pos) return INT_MAX;
        else return INT_MIN;
    }

    ll number=0;
    for(int j=start; j<=end; j++){
        number *= 10;
        number += s[j]-'0';
    }
    if(!pos) number *= -1;
    if(number > INT_MAX) return INT_MAX;
    if(number< INT_MIN) return INT_MIN;

    return number;
}

int main(){
    string s;
    cin>>s;
    int n = myAtoi(s);
    cout<<n<<endl;
    return 0;
}