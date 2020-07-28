#include<iostream>
#include<vector>
#include<stack>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);

vector<int> dailyTemperatures(vector<int>& T) {
    stack<int>s;
    int n=T.size();
    vector<int>ans(n, 0);

    for(int i=n-1; i>=0; i--){
        while(!s.empty() && T[s.top()] <= T[i]){
            s.pop();
        }
        ans[i] = s.empty()?0:s.top()-i;
        s.push(i);
    }
    return ans;
}

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    
    return 0;
}