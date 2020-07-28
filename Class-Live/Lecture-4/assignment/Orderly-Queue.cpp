#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);

string orderlyQueue(string &S, int k)
{
    if (k == 1)
    {
        string ans = S;
        for (int i = 0; i < S.length(); i++)
        {
            string temp = S.substr(i) + S.substr(0, i);
            if (temp.compare(ans) < 0)
                ans = temp;
        }
        return ans;
    }
    else
    {
        sort(S.begin(), S.end());
    }
    return S;
}

int main(){
    int k;
    string s;
    cin>>s;
    cin>>k;
    s = orderlyQueue(s, k);
    cout<<s<<endl;
    return 0;
}