// https://leetcode.com/problems/baseball-game/
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

int calPoints(vector<string>& ops) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    stack<int>s;
    int sum=0;

    for(string i: ops){
        if(i=="C"){
            sum -= s.top();
            s.pop();
        }
        else if(i=="D"){
            s.push(2*s.top());
            sum += s.top();
        }
        else if(i=="+"){
            int a=s.top();s.pop();
            int b=s.top();
            s.push(a);
            s.push(a+b);
            sum += s.top();
        }
        else{
            s.push(stoi(i));
            sum += s.top();
        }
    }

    return sum;
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