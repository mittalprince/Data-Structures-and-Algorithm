#include<iostream>
#include<vector>
#include<cstring>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);

int main(){
    string heading;
    getline(cin, heading);
    string text;
    getline(cin, text);
    int freq[256]={0};
    for(int i=0; i<heading.length(); i++){
        if(heading[i] == ' ') continue;
        freq[heading[i]]++;
    }
    for (int i = 0; i < text.length(); i++)
    {
        if (text[i] == ' ')
            continue;
        freq[text[i]]--;
    }
    bool flag=true;
    for(int i=0; i<256; i++){
        if(freq[i]<0){
            flag=false;
            break;
        }
    }
    if(flag) cout<<"YES\n";
    else cout<<"NO\n";
    return 0;
}