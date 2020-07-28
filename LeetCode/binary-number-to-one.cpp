#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);

int numSteps(string s){
    int ans=0;
    if(s.length() == 1) return ans;
    for(int i=s.length()-1; i>=0;){
        if(s[i] == '0'){
            ans++;
            i--;
        }
        else{
            ans++;
            while(s[i] == '1' && i>0){
                ans++;
                i--;
            }
            if(i==0){
                ans++;
            }
            s[i] = '1';
        }
    }
    return ans;
}
int main(){
    string s;
    cin>>s;
    cout<<numSteps(s)<<endl;
    return 0;
}