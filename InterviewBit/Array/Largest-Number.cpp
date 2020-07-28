// https://www.interviewbit.com/problems/largest-number/
#include<iostream>
#include<vector>
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

bool compare(string a, string b){
    string ab = a.append(b);
    string ba = b.append(a);
    
    return a>b;
}
string largestNumber(const vector<int> &A) {
    int n=A.size();
    string ans="";
    if(!n){
        return ans;
    }
    
    vector<string> temp;
    for(int i=0; i<n; i++){
        temp.push_back(to_string(A[i]));
    }
    sort(temp.begin(), temp.end(), compare);
    bool flag=true;
    for(int i=0; i<n; i++){
        ans += temp[i];
        if(temp[i] != "0"){
            flag = false;
        }
    }
    
    if(flag){
        return "0";
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