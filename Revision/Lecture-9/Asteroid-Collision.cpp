// https://leetcode.com/problems/asteroid-collision/
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

vector<int> asteroidCollision(vector<int>& A) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n=A.size();
    stack<int>s;

    for(int i: A){
        int x = i;
        if(!s.empty() and s.top()>0 and x<0){
            bool elmtPush=true;
            while(!s.empty() and s.top()>0 and x<0){
                if(abs(s.top()) == abs(x)){
                    elmtPush=false;
                    s.pop();
                    break;
                }
                else if(abs(s.top())<abs(x)){
                    s.pop();
                    elmtPush=true;
                }
                else{
                    elmtPush=false;
                    break;
                }
            }
            if(elmtPush)s.push(x);
        }
        else s.push(x);
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

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    int n;
    cin>>n;
    vector<int> arr(n);
    
    return 0;
}