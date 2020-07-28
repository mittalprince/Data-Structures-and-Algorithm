#include<iostream>
#include<vector>
#include<stack>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);

int calPoints(vector<string>& ops) {
    stack<int>s;
    int sum=0;

    for(string i: ops){
        if(i=="C"){
            sum -= s.top();
            s.pop();
        }
        else if(i=="D"){
            sum += (2*s.top());
            s.push(2*s.top());
        }
        else if(i=="+"){
            int a=s.top(); s.pop();
            int b=s.top();
            sum += (a+b);
            s.push(a);
            s.push(a+b);
        }
        else{
            s.push(stoi(i));
            sum += s.top();
        }
    }
    return sum;
}

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    
    return 0;
}