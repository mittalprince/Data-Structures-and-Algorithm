#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
#define MAX 200005

void solve(){
    int n, point;
    cin>>n;
    ll sum_a=0, sum_b=0;
    vector<int> seq_a, seq_b;
    for(int i=0; i<n; i++){
        cin>>point;
        if(point>0){
            sum_a+=point;
            seq_a.push_back(point);
        }
        else{
            sum_b+=abs(point);
            seq_b.push_back(abs(point));
        }
    }
    
    if(sum_a > sum_b){
        cout<<"first\n";
    }
    else if(sum_b>sum_a){
        cout<<"second\n";
    }
    else{
        int i=0, j=0;
        string ans="first";
        bool equal=true;
        while(i<seq_a.size() && j<seq_b.size()){
            // cout<<seq_b[j]<<" "<<seq_a[i]<<endl;
            if(seq_b[j] != seq_a[i]){ 
                equal =false;
                // cout<<seq_b[j]<<" "<<seq_a[i]<<endl;
            }
            if(seq_b[j]>seq_a[i]){
                ans="second";
                break;
            }
            else if(seq_a[i]>seq_b[j]) break;
            i++;
            j++;
        }
        if(equal){
            // cout<<"yes\n";
             if(point < 0){
                cout<<"second\n";
            }
            else cout<<"first\n";
        }
        else cout<<ans<<endl;
    }
}

int main(){
    int t=1;
    // cin>>t;
    while(t--){
        solve();
    }
}