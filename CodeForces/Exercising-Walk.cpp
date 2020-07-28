#include<iostream>
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    int t;
    cin>>t;
    while(t--){
        ll a,b,c,d;
        cin>>a>>b>>c>>d;
        ll x,y,x1,x2,y1,y2;
        cin>>x>>y>>x1>>y1>>x2>>y2;
        if(x2-x1 == 0 && (a>0 || b >0)){
            cout<<"NO\n";
            continue;
        }
        if(y2-y1 == 0 && (c>0 || d >0)){
            cout<<"NO\n";
            continue;
        }
        ll left = (x-x1)+b;
        ll right = (x2-x)+a;
        ll down = (y-y1)+d;
        ll top = (y2-y)+c;
        // cout<<left<<" "<<right<<" "<<top<<" "<<down<<endl;
        if(left<a || right<b || down<c || top<d){
            cout<<"NO\n";
        }
        else{
            cout<<"YES\n";
        }
    }
}