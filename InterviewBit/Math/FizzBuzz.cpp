#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);

vector<string> fizzBuzz(int A) {
    vector<string> ans;
    
    for(int i=1; i<=A; i++){
        string t="";
        if(i%3 == 0) t += "Fizz";
        if(i%5 == 0) t += "Buzz";
        
        if(t.empty()) t = to_string(i);
        ans.push_back(t);
    }
    return ans;
}

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    
    return 0;
}