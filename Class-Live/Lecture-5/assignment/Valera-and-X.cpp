#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);

int main(){
    int n;
    cin>>n;
    bool flag=true;
    int unique=1;
    char dia, nonDia;
    for(int i=0; i<n; i++){
        string s;
        cin>>s;
        if(i==0){
            dia = s[0];
            nonDia = s[1];
            if(dia != nonDia) unique++;
        }
        for(int j=0; j<s.length(); j++){
            if(i==j || (i+j) == (n-1)){
                if(s[j] != dia){
                    flag=false;
                    break;
                }
            }
            else{
                if(s[j] != nonDia){
                    flag=false;
                    break;
                }
            }
        }
    }
    if(flag && unique == 2){
        cout<<"YES\n";
    }
    else cout<<"NO\n";
    return 0;
}