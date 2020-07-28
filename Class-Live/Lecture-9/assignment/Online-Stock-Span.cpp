#include<iostream>
#include<vector>
#include<stack>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);

class StockSpanner {
public:
    stack<pair<int, int> >s;
    StockSpanner() {
        stack<pair<int, int> >();
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
    }
    
    int next(int price) {
        int t=1;
        while(!s.empty() && s.top().first<=price){
            t += s.top().second;
            s.pop();
        }
        
        s.push({price, t});
        return t;
    }
};

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    
    return 0;
}