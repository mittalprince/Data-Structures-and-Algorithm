#include<iostream>
#include<vector>
#include<stack>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);

vector<int> asteroidCollision(vector<int>&a){
    if(a.empty()) return {};

    int n=a.size();
    stack<int> s;

    for(int i=0; i<n; i++){
        int x = a[i];
        if(!s.empty() && s.top()>0 && x<0){
            bool elmtPush=true;
            while(!s.empty() && s.top()>0 && x<0){
                if(abs(s.top()) == abs(x)){
                    elmtPush = false;
                    s.pop();
                    break;
                }
                else if(abs(s.top())< abs(x)){
                    s.pop();
                    elmtPush = true;
                }
                else{
                    elmtPush=false;
                    break;
                }
            }
            if(elmtPush) s.push(x);
        }
        else{
            s.push(x);
        }
    }

    vector<int>ans(s.size());
    int idx = s.size()-1;
    while(!s.empty()){
        ans[idx--] = s.top();
        s.pop();
    }
    return ans;
}

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    ip(arr, n);
    vector<int>res = asteroidCollision(arr);
    for(int i: res){
        cout<<i<<" ";
    }
    cout<<endl;
    return 0;
}