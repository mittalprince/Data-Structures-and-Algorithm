//https://leetcode.com/problems/basic-calculator-ii/
#include<iostream>
#include<vector>
#include<stack>
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

int calculate(string s) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    stack<int>stk;
    char sign = '+';
    int res = 0, temp = 0;

    for(int i=0; i<s.size(); i++){
        if (isdigit(s[i])) temp = temp*10 + (int)(s[i]-'0');
        if(!isdigit(s[i]) && !isspace(s[i]) || i == s.size()-1){
            if(sign == '-'){
                stk.push(-temp);
            }
            else if(sign == '+'){
                stk.push(temp);
            }
            else{
                int top = stk.top();
                stk.pop();
                if(sign == '*'){
                    stk.push(top*temp);
                }
                else{
                    stk.push(top/temp);
                }
            }
            sign = s[i];
            temp=0;
        }
    }

    while(!stk.empty()){
        res += stk.top();
        stk.pop();
    }

    return res;
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