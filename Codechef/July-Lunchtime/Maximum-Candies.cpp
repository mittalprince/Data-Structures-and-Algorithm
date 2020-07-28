// https://www.codechef.com/LTIME86B/problems/CHECHOC
// Reference -> https://www.codechef.com/viewsolution/35947510
#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;

int main(){

    int t;
    cin>>t;
    while(t--){
        int n,m,x,y;
        cin>>n>>m>>x>>y;
        
        ll arr[n][m];

        if(n==1 and m==1){
            cout<<x;
        }
        else if(2*x <= y){
            cout<<x*(n*m);
        }
        else if(y<x){
            ll val1=y;
            ll val2=0;
            ll opt1=0;
            ll opt2=0;

            bool flag1=false, flag2=true;

            for(ll i=0; i<n; i++){
                for(ll j=0; j<m; j++){
                    arr[i][j] = flag2?val1:val2;
                    flag2 = !flag2;
                }
                flag2 = flag1;
                flag1 = !flag1;
            }

            for(ll i=0; i<n; i++){
                for(ll j=0; j<m; j++){
                    opt1 += arr[i][j];
                }
            }

            flag1=true, flag2=false;
            for(ll i=0; i<n; i++){
                for(ll j=0; j<m; j++){
                    arr[i][j] = flag2?val1:val2;
                    flag2 = !flag2;
                }
                flag2 = flag1;
                flag1 = !flag1;
            }
            for(ll i=0; i<n; i++){
                for(ll j=0; j<m; j++){
                    opt2 += arr[i][j];
                }
            }

            cout<<max(opt1, opt2); 
        }
        else{
            ll val1 = x;
            ll val2 = min(x, y-x);
            ll opt1 = 0;
            ll opt2 = 0;

            bool flag1 = false, flag2 = true;

            for(ll i=0; i<n; i++){
                for(ll j=0; j<m; j++){
                    arr[i][j] = flag2?val1:val2;
                    flag2 = !flag2;
                }
                flag2 = flag1;
                flag1 = !flag1;
            }
            for(ll i=0; i<n; i++){
                for(ll j=0; j<m; j++){
                    opt1 += arr[i][j];
                }
            }

            flag1=true, flag2=false;
            for(ll i=0; i<n; i++){
                for(ll j=0; j<m; j++){
                    arr[i][j] = flag2?val1:val2;
                    flag2 = !flag2;
                }
                flag2 = flag1;
                flag1 = !flag1;
            }
            
            for(ll i=0; i<n; i++){
                for(ll j=0; j<m; j++){
                    opt2 += arr[i][j];
                }
            }  

            cout<<max(opt1, opt2);
        } 
        cout<<endl;
    }
    return 0;
}