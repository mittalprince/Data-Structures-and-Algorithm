#include<iostream>
#include<algorithm>
#include<map>
#include<bits/stdc++.h>
using namespace std;

bool comp1(pair<ll,ll>&a, pair<ll,ll>&b){
    return a.second>b.second;
}
bool comp2(pair<ll,ll>&a, pair<ll,ll>&b){
    return a.second<b.second;
}
int main(){
    int n;
    cin>>n;
    vector<pair<ll,ll> >a,b;
    map<pair<ll,ll>, int>m;
    ll x,y;
    for(int i=0; i<n; i++){
        cin>>x>>y;
        m[make_pair(x,y)] = i+1;
        if(x<y){
            a.push_back(make_pair(x,y));
        }
        else{
            b.push_back(make_pair(x,y));
        }
    }
    sort(a.begin(), a.end(), comp1);
    sort(b.begin(), b.end(), comp2);
    if(a.size()>=b.size()){
        cout<<a.size()<<endl;
        for(auto i: a){
            cout<<(m[i]+1)<<" ";
        }
        cout<<endl;
    }
    else{
        cout<<b.size()<<endl;
        for(auto i: b){
            cout<<(m[i]+1)<<" ";
        }
        cout<<endl;
    }

}