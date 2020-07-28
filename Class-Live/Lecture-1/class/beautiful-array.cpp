#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;

vector<int> beautifulArray(int n){
    vector<int> res = {1};
    int int_temp;

    while(res.size()<n){
        vector<int> temp_seq;
        for(int i:res){
            int_temp = i*2-1;
            if(int_temp<=n) temp_seq.push_back(int_temp);
        }

        for(int i: res){
            int_temp = i*2;
            if(int_temp<=n) temp_seq.push_back(int_temp);
        }
        res = temp_seq;
    }
    return res;
}

int main()
{
    int n;
    cin >> n;
    vector<int> res = beautifulArray(n);
    for(int i: res){
        cout<<i<<" ";
    }
    cout<<endl;
    return 0;
}