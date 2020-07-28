#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;
int tempCount[100000];

bool comp(string a, string b){
    string ab=a+b;
    string ba=b+a;

    ll ab_ct=0, ba_ct=0;
    ll h=0;
    for(ll i=ab.length()-1; i>=0; i--){
        if(ab[i] == 'h') h++;
        else ab_ct += h;
    }
    h=0;
    for(ll i=ba.length()-1; i>=0; i--){
        if(ba[i] == 'h') h++;
        else ba_ct += h;
    }

    return ab_ct>ba_ct;
}

bool compare(string str1, string str2){
    long long int pairsA = 0, pairsB = 0;  
    string temp = str1 + str2;
    int len = temp.length();
    if(temp[len-1] == 'h'){
        tempCount[len-1] = 1;
    }else{
        tempCount[len-1] = 0;
    }
    for(int i=len-2; i>= 0; --i){   
        tempCount[i] = tempCount[i+1];
        if(temp[i] == 'h'){
            tempCount[i] += 1;
        }
    }
    for(int i=0; i<len; ++i){
        if(temp[i] == 's'){
            pairsA += tempCount[i];
        }
    }
    temp = str2 + str1;
    if(temp[len-1] == 'h'){
        tempCount[len-1] = 1;
    }else{
        tempCount[len-1] = 0;
    }
 
    for(int i=len-2; i>= 0; --i){   
        tempCount[i] = tempCount[i+1];
        if(temp[i] == 'h'){
            tempCount[i] += 1;
        }
    }
    for(int i=0; i<len; ++i){
        if(temp[i] == 's'){
            pairsB += tempCount[i];
        }
    }
    return pairsA > pairsB;
}
 
int main(){
    int n;
    cin>>n;
    vector<string>arr;
    string temp;
    for(int i=0; i<n; i++){
        cin>>temp;
        arr.push_back(temp);
    }
    sort(arr.begin(), arr.end(), comp);

    ll h=0;
    ll ans=0;
    string concat="";
    for(string i: arr){
        // cout<<i<<endl;
        concat += i;
    }
    for(ll i=concat.length()-1; i>=0; i--){
        if(concat[i] == 'h')h++;
        else ans += h;
    }
    cout<<ans<<endl;
}