#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);

vector<int> diStringMatch(string s){
    int n=s.length();
    int I=0, D=n;
    vector<int> ans;
    for(int i=0; i<n; i++){
        if(s[i] == 'I'){
            ans.push_back(I);
            I++;
        }
        else{
            ans.push_back(D);
            D--;
        }
    }
    ans.push_back(D);
    return ans;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        cin >> s;
        vector<int> res = diStringMatch(s);
        for (int i : res)
            cout << i << " ";
        cout << endl;
    }
    return 0;
}