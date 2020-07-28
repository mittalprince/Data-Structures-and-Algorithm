// https://leetcode.com/problems/design-browser-history/
#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define debug(x) cout<<x<<"\n";
#define inf 1e9
#define INF 1e16
#define MOD 1000000007

class BrowserHistory {
public:
    unordered_map<int, string>urls;
    int total_urls, curr_url;
    
    BrowserHistory(string homepage) {
        urls.clear();
        total_urls=1, curr_url=1;
        urls[curr_url]=homepage;
    }
    
    void visit(string url) {
       if(curr_url == total_urls){
           urls[++curr_url]=url;
           total_urls++;
       }
        else{
            urls[++curr_url]=url;
            total_urls = curr_url;
        }
    }
    
    string back(int steps) {
        int x = curr_url-steps;
        if(x<1){
            curr_url=1;
            return urls[1];
        }
        curr_url = x;
        return urls[x];
    }
    
    string forward(int steps) {
        int x = curr_url+steps;
        if(x>total_urls){
            curr_url=total_urls;
            return urls[curr_url];
        }
        curr_url = x;
        return urls[x];
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */

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