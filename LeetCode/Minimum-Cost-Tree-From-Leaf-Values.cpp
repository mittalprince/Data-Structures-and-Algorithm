// https://leetcode.com/problems/minimum-cost-tree-from-leaf-values/
#include<iostream>
#include<vector>
#include<stack>
#include<climits>
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

/*
Logic Used: we maintain al number in dec order in satck 
and when the order change means become incre me pop element until dec order follow

To remove a number arr[i], it needs a cost a * b, where b >= a and also an element of the array. 
To minimize the cost of removal, the idea is to minimize b. To compute the non-leaf node there are two candidates, 
that is the first largest number on the left and the first largest number on the right. 
The cost to remove arr[i] is a * min(left, right). 
It can be further decomposed as to find the next greater element in the array, on the left and one right.
*/

int mctFromLeafValues(vector<int>& arr) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    stack<int> s;
    int res= 0;
    s.push(INT_MAX);
    for(int i=0; i<arr.size(); i++){
        while(!s.empty() && arr[i]>=s.top()){
            int curr = s.top();
            s.pop();
            res += curr*min(arr[i], s.top());
        }
        s.push(arr[i]);
    }
    while(s.size()>2){
        int x = s.top();
        s.pop();
        int y = s.top();
        res += x*y;
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