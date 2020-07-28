#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);

string strWithout3a3b(int a, int b){
    string ans="";

    // while(a>0 || b>0){
    //     if(a<b){
    //         if(0 < b--) ans += 'b';
    //         if(0 < b--) ans += 'b';
    //         if(0 < a--) ans += 'a';
    //     }
    //     else if(a>b){
    //         if(0 < a--) ans += 'a';
    //         if(0 < a--) ans += 'a';
    //         if(0 < b--) ans += 'b';
    //     }
    //     else{
    //         if(0 < a--) ans += 'a';
    //         if(0 < b--) ans += 'b';
    //     }
    // }

    int first=-1, second=-1;

    while(a || b){
        if(a>b){
            if(first==-1||second==-1||(first!=second)||((first==second)&&first!=1)){
                ans+='a';
                second=first;
                first=1;
                a--;
            }
            else{
                ans += 'b';
                second = first;
                first = 2;
                b--;
            }
        }
        else{
            if(first==-1||second==-1||(first!=second)||((first==second)&&first!=2)){
                ans+='b';
                second=first;
                first=2;
                b--;
            }
            else{
                ans += 'a';
                second = first;
                first = 1;
                a--;
            }
        }
    }
    return ans;
}

int main(){
    int a,b;
    cin>>a>>b;
    string ans = strWithout3a3b(a, b);
    cout<<ans<<endl;
    return 0;
}