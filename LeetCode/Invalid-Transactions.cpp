// https://leetcode.com/problems/invalid-transactions/
#include<iostream>
#include<vector>
#include<cstring>
#include<sstream>
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

class transaction
{
  public:
  string name;
  int time;
  int amount;
  string city;
  bool isValid;
};
vector<string> invalidTransactions(vector<string>& transactions) 
{
    vector<transaction>v;
    for(int i=0;i<transactions.size();i++)
    {
        transaction t;
        stringstream ss(transactions[i]);
        string name;     getline(ss,name,',');   t.name=name;  
        string time;     getline(ss,time,',');   t.time=stoi(time);
        string amount;   getline(ss,amount,','); t.amount=stoi(amount);
        string city;     getline(ss,city,',');   t.city=city;

        t.isValid=true;
        v.push_back(t);
    }
    for(int i=0;i<v.size();i++)
    {
        if(v[i].amount>1000)
        {
            v[i].isValid=false;
            continue;
        }
        for(int j=0;j<v.size();j++)
        {
            if(v[i].name==v[j].name&&v[i].city!=v[j].city&&abs(v[i].time-v[j].time)<=60)
            {
                v[i].isValid=false;
                v[j].isValid=false;
                continue;
            }
        }
    }
    vector<string>res;
    for(int i=0;i<v.size();i++)
    {
        if(!v[i].isValid)
        {
            string temp;
            temp+=v[i].name+","+to_string(v[i].time)+","+to_string(v[i].amount)+","+v[i].city;
            res.push_back(temp);
        }   
    }
    return res;
}

int main(){

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    int n;
    cin>>n;
    vector<int> arr(n);
    
    return 0;
}