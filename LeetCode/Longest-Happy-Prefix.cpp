#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);

// https://www.geeksforgeeks.org/longest-prefix-also-suffix/
// use KMP resetTable logic, need to find longest prefix which is also sufix
string longestPrefix(string s){
    int n = s.length();
    vector<int> v(n, 0);
    int j = 0;
    for (int i = 1; i < n; i++)
    {
        while (j > 0 && s[j] != s[i])
        {
            j = v[j - 1];
        }
        if (s[i] == s[j])
        {
            j++;
            v[i] = j;
        }
        else
        {
            if (j == 0)
            {
                v[i] = 0;
            }
        }
    }
    return s.substr(0, v[n - 1]);
}

int main(){
    string s;
    cin>>s;

    string ans = longestPrefix(s);
    cout<<ans<<endl;
    return 0;
}