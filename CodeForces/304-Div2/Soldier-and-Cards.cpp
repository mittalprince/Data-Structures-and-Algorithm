// https://codeforces.com/contest/546/problem/C
#include<iostream>
#include<vector>
#include<queue>
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

/*
Logic; Use Brute Force, but to find the total steps and winner.

But how to check the sol does not exist, for this the total steos can not exceed 106.
Or you can use 10! total steps both will work, 10! as because we assume the combination of n
*/

int main(){

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    int n;
    cin>>n;
    
    deque<int>a,b;

    int k1;
    cin>>k1;
    for(int i=0; i<k1; i++){
        int x;
        cin>>x;
        a.push_back(x);
    }

    int k2;
    cin>>k2;
    for(int i=0; i<k2; i++){
        int x;
        cin>>x;
        b.push_back(x);
    }

    bool winner=true;
    int ct=0;

    while(ct<=106){
        if(a.empty()){
            cout<<ct<<" "<<2<<endl;
            return 0;
        }
        if(b.empty()){
            cout<<ct<<" "<<1<<endl;
            return 0;
        }

        int a_front = a.front();
        int b_front = b.front();
        a.pop_front(); b.pop_front();

        if(a_front<b_front){
            b.push_back(a_front);
            b.push_back(b_front);
        }
        else{
            a.push_back(b_front);
            a.push_back(a_front);
        }
        ct++;
    }
    cout<<"-1\n";
    return 0;
}