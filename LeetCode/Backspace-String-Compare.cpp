#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);

bool backspaceCompare(string S, string T)
{
    int i = S.length() - 1, j = T.length() - 1;
    int skipS = 0, skipT = 0;

    while (i >= 0 || j >= 0)
    {

        while (i >= 0)
        {
            if (S[i] == '#')
            {
                skipS++;
                i--;
            }
            else if (skipS > 0)
            {
                skipS--;
                i--;
            }
            else
                break;
        }
        while (j >= 0)
        {
            if (T[j] == '#')
            {
                skipT++;
                j--;
            }
            else if (skipT > 0)
            {
                skipT--;
                j--;
            }
            else
                break;
        }

        if (i >= 0 && j >= 0 && S[i] != T[j])
            return false;
        if ((i >= 0 && j < 0) || (i < 0 && j >= 0))
            return false;
        i--;
        j--;
    }
    return true;
}

int main(){
    string s,t;
    cin>>s>>t;
    backspaceCompare(s,t)?cout<<"true\n": cout<<"false\n";
    return 0;
}