//https://leetcode.com/problems/basic-calculator/
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

    stack <int> nums, ops;
    int num = 0;
    int rst = 0;
    int sign = 1;

    for(char i: s){
        if(isdigit(i)){
            num = num*10+(i-'0');
        }
        else{
            rst += num*sign;
            num=0;
            if(i=='+')sign=1;
            else if(i=='-')sign=-1;
            else if(i=='('){
                ops.push(sign);
                nums.push(rst);
                rst=0;
                sign=1;
            }
            else if(i==')' and ops.size()){
                rst = ops.top()*rst+nums.top();
                ops.pop();
                nums.pop();
            }
        }
    }

    rst += sign * num;
    return rst;
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