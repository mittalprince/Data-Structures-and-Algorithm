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

bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    stack<int>s;
    int i=0, n=popped.size();

    for(int a: pushed){
        while(!s.empty() && i<n && s.top() == popped[i]){
            s.pop();
            i++;
        }
        s.push(a);
    }

    while(!s.empty() && i<n && s.top() == popped[i]){
        s.pop();
        i++;
    }

    return s.empty();

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