#include<iostream>
#include<vector>
#include<stack>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);

/*
string str=leet2code3, k=10
str = leetleetcodeleetleetcodeleetleetcode
*/

string decodeAtIndex(string str, int k){
    stack<pair<string, long long int> >s;
    int n=str.length();

    for(int i=0; i<n; i++){
        string x="";
        while(i<n && (str[i]>'9' || str[i]<'0')){
            x += str[i];
            i++;
        }
        long long int len = (x.length() + (s.empty() ? 0 : s.top().second)) * (str[i] - '0');
        s.push({x, len});

        // push into stack until we reach the string of length at least k, after this we break loop
        if(len >= k) break;
    }

    string ans="";
    while(!s.empty()){
        pair<string, long long int> top = s.top();
        s.pop();
        string x = top.first;
        long long int len = top.second;

        k = k%(x.length() + (s.empty()?0:s.top().second));

        if(k==0){
            k = (x.length() + (s.empty()?0:s.top().second));
        }
        if(s.empty()){
            ans = x[k-1];
            return ans;
        }
        else if(k>s.top().second){
            // i.e we need to find string from the popped string
            ans = x[k-s.top().second-1];
            return ans;
        }
    }
    return ans;
}

int main(){
    string s;
    cin>>s;
    int k;
    cin>>k;
    cout<<decodeAtIndex(s, k)<<endl;
    return 0;
}