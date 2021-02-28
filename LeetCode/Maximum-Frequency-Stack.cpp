//https://leetcode.com/problems/maximum-frequency-stack/
#include<iostream>
#include<vector>
#include<stack>
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

class FreqStack {
public:
    unordered_map<int, int>freq;
    unordered_map<int, stack<int> >m;
    int maxFreq=0;
    
    FreqStack() {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
    }
    
    void push(int x) {
        maxFreq = max(maxFreq, ++freq[x]);
        m[freq[x]].push(x);
    }
    
    int pop() {
        int ans = m[maxFreq].top();
        m[maxFreq].pop();
        if(!m[freq[ans]--].size())maxFreq--;
        return ans;
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
}