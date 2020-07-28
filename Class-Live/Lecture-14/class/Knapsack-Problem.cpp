#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);

map<int, ll> m;

int main(){
    int n,c,w,W=0;
    cin>>n;
    vector<int>one, two;
    for(int i=0; i<n; i++){
        cin>>w>>c;
        if(w==1){
            one.push_back(c);
        }
        else two.push_back(c);
        W += w;
    }
    
    sort(one.begin(), one.end());
    sort(two.begin(), two.end());

    int p=one.size(), q=two.size();
    ll res=0;

    for(int i=2; i<=W; i+=2){
        ll res1=0, res2=0;
        if(q>0){
            res2 = two[q-1];
        }
        if(p>0){
            res1 += one[p-1];
            if(p>1){
                res1 += one[p-2];
            }
        }

        if(res2>res1){
            res += res2;
            q--;
        }
        else{
            res += res1;
            p -= 2;
        }
        m[i] = res;
    }

    res=0;
    p=one.size(), q=two.size();

    if(p>0){
        m[1] = one[p-1];
        p--;
        res=m[1];
    }

    for(int i=3; i<=W; i+=2){
        ll res1=0, res2=0;
        if(q>0){
            res2 = two[q-1];
        }
        if(p>0){
            res1 += one[p-1];
            if(p>1){
                res1 += one[p-2];
            }
        }

        if(res2>res1){
            res += res2;
            q--;
        }
        else{
            res += res1;
            p -= 2;
        }
        m[i] = res;
    }
    // cout<<W<<endl;
    for(int i=1; i<=W; i++){
        cout<<m[i]<<" ";
    }
    cout<<endl;
    return 0;
}