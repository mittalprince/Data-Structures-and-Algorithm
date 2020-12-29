//https://leetcode.com/problems/count-and-say/
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

string countAndSay(int n) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string result="1";
    n--;
    while(n){
        char currchar=result[0];
        int ct=0;
        string temp="";
        for(char i: result){
            if(i==currchar){
                ct++;
            }
            else{
                temp.push_back('0'+ct);
                temp.push_back(currchar);
                ct=1;
                currchar=i;
            }
        }
        temp.push_back('0'+ct);
        temp.push_back(currchar);
        result=temp;
        n--;
    }
    return result;
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