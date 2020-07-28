#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);

// a substr is good if it contain a palindrone
// task -> find all even length, odd length good substr

// point samaj karna yeh hai string ke har ith element ko add karenge
// then check ki isse add karne se kitne odd bade and even

// qki hum har ith ke liye calcul kar rahe hai toh its obvios that for this ith pos
// there is sone palindome from 0-i such that it become good substr so every addition of char
// will incrs odd and even good substr

// observation agr ith pos pr char add karta hai toh humme yeh check karna hai ki
// same parity pos par kitna elemt isse match hota hai, jitne elment match hone utne correspoding
// even odd ka count badega

// if we add at odd pos
// toh odd ka count utna time badega, jitne same char odd pos par hoo
// and even count badega, jitne even pos par same char hai

// if we add at even place
// toh odd ka count utna time se badega jitne same char even pos par hoo (4-5-6), we see for 4-6 odd len
// and even ka count badega, jitne odd pos char same char hai

// now as indexing start from 0, so if we add at odd pos, it means addition at even place (i+1 in real)

void solve(){
    string s;
    cin>>s;
    ll ct[2][2];
    for(int i=0; i<2; i++)
        for(int j=0; j<2; j++)
            ct[i][j]=0;
    ll even=0, odd=0;

    for(int i=0; i<s.length(); i++){
        odd++;
        if(i&1){ //adition at even pos
            even += ct[s[i]-'a'][1];
            odd += ct[s[i]-'a'][0];
            ct[s[i]-'a'][0]++;
        }
        else{ // adition at odd pos
            odd += ct[s[i]-'a'][1];
            even += ct[s[i]-'a'][0];
            ct[s[i]-'a'][1]++;
        }
    }

    cout<<even<<" "<<odd<<endl;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}