#include<iostream>
#include<vector>
#include<queue>
#include<map>
#include<set>
#include<iterator>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);

int main(){
    fstIO;
    int n, type, price;
    cin>>n;
    string stock;
    map<string, ll> stock_record;
    set<pair<ll, string> > sorted_stock;
    for(int i=1; i<=n; i++){
        cin>>type;
        cin>>stock;
        if(type == 1 || type == 2){
            cin>>price;
            if(type == 1){
                sorted_stock.insert({price, stock});
            }
            else{
                set<pair<ll, string> >::iterator it = sorted_stock.find({stock_record[stock], stock});
                if( it != sorted_stock.end()){
                    sorted_stock.erase(it);
                }
                sorted_stock.insert({price, stock});
            }
            stock_record[stock] = price;
        }
        else{
            set<pair<ll, string> >::iterator it = sorted_stock.begin();
            cout<<(it->second)<<" "<<i<<endl;
            if( it != sorted_stock.end()){
                sorted_stock.erase(it);
            }
            stock_record.erase(it->second);
        }

    }
    return 0;
}