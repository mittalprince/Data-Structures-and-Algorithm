#include<iostream>
#include<vector>
#include<set>
#include<map>
#include<cstring>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define MAX 4000005

int main(){
    int n,k;
    cin>>n>>k;
    
    ll arr[n], next[n+1], last[n+1];
    ip(arr, n);
    
    memset(last, MAX, sizeof(last));
    for(int i=n-1; i>=0; i--){
        next[i] = last[arr[i]];
        last[arr[i]] = i;
    }

    int cost=0;
    //sorted books by their next-request time.
    multiset<pair<ll, ll> >books_idx;
    map<ll, bool>book_present;

    for(int i=0; i<n; i++){
        if(book_present[arr[i]]){
            auto it = books_idx.find({i, arr[i]});
            // if(it != books_idx.end()){
                books_idx.erase(it);
                books_idx.insert({next[i], arr[i]});
            // }
        }
        else{
            if(books_idx.size()>=k){
                auto top = *books_idx.rbegin();
                books_idx.erase(--books_idx.end());
                book_present[top.second] = false;
            }
            books_idx.insert({next[i], arr[i]});
            book_present[arr[i]]=true;
            cost++;
        }
    }

    cout<<cost<<endl;
    return 0;
}