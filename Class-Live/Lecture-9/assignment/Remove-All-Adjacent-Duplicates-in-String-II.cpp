#include<iostream>
#include<vector>
#include<stack>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);

string removeDuplicates(string s, int k) {
    
    stack<pair<char, int> >S;

    int i = 0, n=s.length();
    pair<char,int> curr;

    while(i<n){
        curr = {s[i], 0};
        while(i<n && s[i] == curr.first){
            i++;
            curr.second++;
        }

        if(!S.empty() && S.top().first == curr.first){
            curr.second += S.top().second;
            S.pop();
        }
        curr.second %= k;
        if(curr.second) S.push(curr);
    }

    string ans="";
    while(!S.empty()){
        pair<char, int> p=S.top();
        S.pop();
        for(int i=0; i<p.second; i++){
            ans = p.first+ans;
        }
    }
    return ans;
}

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    
    return 0;
}