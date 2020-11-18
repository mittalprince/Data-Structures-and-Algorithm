// https://leetcode.com/problems/design-an-ordered-stream/
#include<iostream>
#include<vector>
#include<map>
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

class OrderedStream {
public:
    map<int, string>orders;
    int ptr;
    
    OrderedStream(int n) {
        ptr=1;
    }
    
    vector<string> insert(int id, string value) {
        orders[id]=value;
        
        if(ptr==id and orders.count(ptr)){
            vector<string>ans;
            while(orders.count(ptr)){
                ans.push_back(orders[ptr++]);
            }
            return ans;
        }
        return {};
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