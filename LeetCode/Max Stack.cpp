// https://medium.com/@NikhithaAthukuri/max-stack-070d5f854abd
#include<iostream>
#include<vector>
#include<list>
#include<map>
#include<iterator>
#include<algorithm>
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

class MaxStack{
private:
    list<int> dl;
    map<int, vector<list<int>::iterator>>m; // key-> item, val -> position (list ith pos iterator)

public:
    MaxStack(){
        dl.clear();
        m.clear();
    }
    void push(int x){
        dl.push_back(x);
        m[x].push_back(--dl.end());
    }
    int top(){
        return *dl.rbegin();
    }
    int pop(){
        int temp = top();
        dl.pop_back();
        m[temp].pop_back();
        if(m[temp].size() == 0)m.erase(temp);
        return temp;
    }
    int peekMax(){
        return m.rbegin()->first;
    }
    int popMax(){
        int temp = peekMax();
        auto it = m[temp].back();
        m[temp].pop_back();
        dl.erase(it);
        if(m[temp].size() == 0)m.erase(temp);
        return temp;
    }
}

int main(){

/*
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
*/

    int n;
    cin>>n;
    vector<int> arr(n);
    
    return 0;
}