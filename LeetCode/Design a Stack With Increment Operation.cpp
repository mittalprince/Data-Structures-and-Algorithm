// https://leetcode.com/problems/design-a-stack-with-increment-operation/
#include<iostream>
#include<vector>
#include<unordered_map>
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

class CustomStack {
public:
    vector<int> s;
    int cs;
    int ms;
    CustomStack(int maxSize) {
        cs=0;
        ms=maxSize;
    }

    void push(int x) {
        if(cs < ms){
            s.push_back(x);
            cs++;
        }
    }

    int pop() {
        if(!s.empty()){
            int t=s.back();
            cs--;
            s.pop_back();
            return t;
        }
        return -1;
    }

    void increment(int k, int val) {
        for(int i=0; i<k && i<s.size(); i++){
            s[i] += val;
        }
    }
};
int main(){

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    int n;
    cin>>n;
    vector<int> arr(n);

    return 0;
