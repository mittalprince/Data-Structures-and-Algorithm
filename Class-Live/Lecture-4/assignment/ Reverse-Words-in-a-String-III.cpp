#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);

void reverse(int i, int j, string &a){
    while(i<j){
        swap(a[i], a[j]);
        i++;
        j--;
    }
}
string reverseWords(string s){
    int i=0;
    int n=s.length();

    while(i<n){
        if(s[i]==' '){
            i++;
            continue;
        }
        int j=i+1;
        while(j<n && s[j] != ' ')j++;
        if(j-i>1){
            reverse(i, j-1, s);
        }
        i=j;
    }
    return s;
}

int main(){
    string s;
    cin>>s;
    s = reverseWords(s);
    cout<<s<<endl;
    return 0;
}