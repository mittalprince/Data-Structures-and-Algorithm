//https://leetcode.com/problems/reformat-phone-number/
#include<iostream>
#include<vector>
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

string reformatNumber(string number) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int>t;
    for(char i: number){
        if(i>='0' and i<='9'){
            t.push_back(i);
        }
    }
    string ans="";

    while(t.size()>4){
        if(!ans.empty()){
            ans += "-";
        }
        for(int i=0; i<3; i++){
            ans += t[0];
            t.erase(t.begin());
        }
    }

    if(!ans.empty())ans += "-";
    if(t.size()==2){
        ans += t[0];
        ans += t[1];
    }
    else if(t.size()==3){
        ans += t[0];
        ans += t[1];
        ans += t[2];
    }
    else{
        ans += t[0];
        ans += t[1];
        ans += "-";
        ans += t[2];
        ans += t[3];
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